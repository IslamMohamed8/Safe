#include "State_Machine.h"
#include "APP.h"
#include <util/delay.h>



/****************************************************
*  					Global Variables  			    *
*****************************************************/

typedef enum {NEW_PASSWORD , MASTER_MODE , CONFIRM_PASSWORD , OLD_PASSWORD , ENTER_PASSWORD , OPEN_SAFE , CLOSE_SAFE}State;

static State state = NEW_PASSWORD;


static volatile UINT16 password = 0;
static volatile UINT16 master_password = 0;
static volatile UINT16 confirmed_pass = 0;
static volatile UINT16 old_password = 0;
static volatile UINT16 entered_password = 0;

static UINT8 mistakes = 0; // counts number of mistakes
static UINT8 counter = 0;

static UINT8 function_flag = READY;




/****************************************************
*  					Functions						*
*****************************************************/




/* 	 Function    : state_machine
**   Parameters  : None
**   Return      : None
**   Description : It will make the state machine
*/
void state_machine(void){

	UINT8 change_password_button = 'C' - '0';


	switch(state){
		case NEW_PASSWORD:
			if(function_flag == READY){
				print_enter_new_password();
				function_flag = DONE;
			}

			get_password(&password);
			if(get_key_counts() == NUMBER_OF_DIGITS_IN_PASSWORD){
			set_key_counts(RESET); //Clear the counter
			state = CONFIRM_PASSWORD;
			_delay_ms(250);
			function_flag = READY;
			}
		break;
		case MASTER_MODE:

			if(function_flag == READY){
			print_enter_master_password();
			function_flag = DONE;
			}
            get_password(&master_password);
            if(get_key_counts()== NUMBER_OF_DIGITS_IN_PASSWORD){
            	UINT8 check_if_error = 0 ;
            	set_key_counts(RESET);


                if( master_password == MASTER_PASSWORD ){
                	function_flag = READY;
                	state = NEW_PASSWORD;
                	password = RESET;
                	check_if_error = 1 ;
                }
                master_password = RESET;
                print_invalid(check_if_error);
                _delay_ms(250);
                print_enter_master_password();
                    //     remove_password_from_LCD();
              }

		break;
		case CONFIRM_PASSWORD:
			if(function_flag == READY){
			print_enter_confirm_password();   //Display Confirmation Text
			function_flag = DONE;
			}

			get_password(&confirmed_pass); //Function To Get Confirm Password
			if(get_key_counts()== NUMBER_OF_DIGITS_IN_PASSWORD){
			set_key_counts(RESET);
			if(confirmed_pass != password) //Comparing With Default Password
			{
				state = NEW_PASSWORD;
				password = RESET;
				_delay_ms(250);
				function_flag = READY;
			}
			else{
				state = OPEN_SAFE;
				_delay_ms(250);
				function_flag = READY;
				}
			confirmed_pass = RESET;
			}
		break;
			case OLD_PASSWORD:
			if(function_flag == READY){
			print_enter_old_password();
			function_flag = DONE;
			}
			/* checks if the password user ENTERED "correct" or "wrong"
			 * - correct ---->>>>   goes to "NEW_PASSWORD" state machine
			 * - false   ---->>>>  increment the counter by 1 and return to "OLD_PSSWORD" state machine
			 */
			get_password(&old_password);

			if(get_key_counts()== NUMBER_OF_DIGITS_IN_PASSWORD){
			   set_key_counts(RESET);
				if (old_password == password)
				{
					state = NEW_PASSWORD;
					password = RESET;
					_delay_ms(250);
					counter = RESET;
					function_flag = READY;
				}
				else
				{
					print_number_of_mistakes(counter);
					_delay_ms(250);
					print_enter_old_password();
				//	remove_password_from_LCD();
					counter++;
					if (counter == NUMBER_OF_TRIALS)
					{

						counter = RESET ;
						state = MASTER_MODE;
						function_flag = READY;
					}

				}

				old_password = RESET;
			}
			break;
		case ENTER_PASSWORD:
			if(function_flag == READY){
			print_enter_password();
			function_flag = DONE;
			}
			 // taking pass or key from the user

			/* checking if the user enter "correct pass" , "wrong pass" or "key"
			 * *******          if          ********
			 * "correct pass" ------>>>>>>  open safe
			 * "wrong pass" ------>>>>>>  increment mistakes variables until it reaches 3 and then goes to "MASTER_MODE" state machine
			 * "key" ------>>>>>>  goes to "OLD_PASSWORD" state machine
			 */

			get_password(&entered_password);

			if (entered_password == change_password_button)
			{
				remove_password_from_LCD();
				set_key_counts(RESET);
				entered_password = RESET;
				mistakes = RESET; // to reset the number of mistakes
				state = OLD_PASSWORD;
				_delay_ms(250);
				function_flag = READY;
			}
			else{
				if(get_key_counts()== NUMBER_OF_DIGITS_IN_PASSWORD){
				set_key_counts(RESET);

					if(entered_password == password)
					{
						mistakes = RESET;
						state = OPEN_SAFE;
						_delay_ms(250);
						function_flag = READY;
					}
					else
					{
						print_number_of_mistakes(mistakes);
						_delay_ms(250);
						print_enter_password();
						//remove_password_from_LCD();
						mistakes ++; // increase the number of mistakes
						if (mistakes == NUMBER_OF_TRIALS)
						{
							mistakes = RESET;
							state = MASTER_MODE;
							function_flag = READY;
						}

					}
					entered_password = RESET;
				}
			 }


			break;
		case OPEN_SAFE:

			open_safe();
			wait_in_second(3);
			state = CLOSE_SAFE;
		break;
		case CLOSE_SAFE:
	        close_safe();
			state = ENTER_PASSWORD;
		break;
		

	}


}

		

		


