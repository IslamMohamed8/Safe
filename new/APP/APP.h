#ifndef APP_H_
#define APP_H_


#include "../LIB/STD_TYPES.h"



/******************************************************************************/
/*					   			Defined Constants				 			  */
/******************************************************************************/

#define MASTER_PASSWORD 					5555
#define NUMBER_OF_DIGITS_IN_PASSWORD  		4

#define DONE 								1
#define READY 								2

#define RESET   							0
#define NUMBER_OF_TRIALS 					3


/******************************************************************************/
/*								Functions Prototype				 			  */
/******************************************************************************/


/* 	 Function    : print_enter_new_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter New Pass "
*/
void print_enter_new_password(void);




/* 	 Function    : get_password
**   Parameters  : None
**   Return      : password
**   Description : It will get key from user , print '*' on LCD
*/
void get_password(UINT16* passcode);




/* 	 Function    : get_key_counts
**   Parameters  : None
**   Return      : number of keys entered by the user
**   Description : It will get number of keys entered by the user
*/
UINT8 get_key_counts(void);




/* 	 Function    : set_key_counts
**   Parameters  : number of counts
**   Return      : None
**   Description : It will set number of keys entered by the user
*/
void set_key_counts(UINT8 num);




/* 	 Function    : print_enter_old_password
**   Parameters  : None
**   Return      : None
**   Description : it clears the LCD then prints " enter old password " on LCD
*/
void print_enter_old_password(void);



/* 	 Function    : print_enter_master_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter master Password "
*/
void print_enter_master_password(void);


/* 	 Function    : print_enter_confirm_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter Confirmation Pass
*/
void print_enter_confirm_password(void);


/* 	 Function    : print_enter_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter Pass "
*/
void print_enter_password(void);




/* 	 Function    : open_safe
**   Parameters  : None
**   Return      : None
**   Description : It will determination of motor direction and open the safe
*/
void open_safe(void);


/* 	 Function    : close_safe
**   Parameters  : None
**   Return      : None
**   Description : It will close the safe
*/
void close_safe(void);


/* 	 Function    : wait_in_second
**   Parameters  : time
**   Return      : None
**   Description : It will wait for user enter seconds
*/
void wait_in_second(UINT8 time);



/* 	 Function    : System_Init
**   Parameters  : None
**   Return      : None
**   Description : It will Initialize the system (LCD - Stepper - Keypad)
*/
void System_Init(void);


/* 	 Function    : remove_password_from_LCD
**   Parameters  : None
**   Return      : None
**   Description : It will remove the '*' on the LCD , put ' ' instead
*/
void remove_password_from_LCD(void);


void print_number_of_mistakes(UINT8 mistakes);

void print_invalid(UINT8 check_if_error);

#endif /* APP_H_ */

