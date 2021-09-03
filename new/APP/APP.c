#include "APP.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"
#include "../HAL/Stepper/Stepper.h"
#include <util/delay.h>  // so i can use _dealy_ms() function

static UINT8 keys_counter = 0;

/* 	 Function    : print_enter_new_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter New Pass "
*/
void print_enter_new_password(void){

	LCD_Clear();
	LCD_WriteSentence(" Enter New Pass ");
	LCD_2nd_Line();
}


/* 	 Function    : get_password
**   Parameters  : None
**   Return      : password
**   Description : It will get key from user , print '*' on LCD
*/
void get_password(UINT16* passcode){
	UINT8 digit;
	UINT8 key;

	key =Keypad_GetKey();
	if(key != NO_KEY_IS_PRESSED){
	/******* converting from ASCII to integer (Decimal) *******/
		digit = key - '0'; //'0' = 48 in ASCII
		*passcode *= 10 ;
		*passcode += digit;
		LCD_WriteData('*');
		keys_counter++;

	}


}



/* 	 Function    : get_key_counts
**   Parameters  : None
**   Return      : number of keys entered by the user
**   Description : It will get number of keys entered by the user
*/
UINT8 get_key_counts(){
	return keys_counter;
}



/* 	 Function    : set_key_counts
**   Parameters  : number of counts
**   Return      : None
**   Description : It will set number of keys entered by the user
*/
void set_key_counts(UINT8 num){
	 keys_counter = num;
}



/*   Function    : print_enter_confirm_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print Enter Confirmation Pass
*/
void print_enter_confirm_password(void)
{
	LCD_Clear();
	LCD_WriteSentence(" Confirm Pass ");
	LCD_2nd_Line();
}



/* 	 Function    : print_enter_master_password
**   Parameters  : None
**   Return      : None
**   Description : It will clear LCD and print " Enter master Password "
*/
void print_enter_master_password(void){

	LCD_Clear();
	LCD_WriteSentence("Master password");
	LCD_2nd_Line();
}

/* 	 Function    : print_enter_old_password
**   Parameters  : None
**   Return      : None
**   Description : it clears the LCD then prints enter old password on LCD
*/
void print_enter_old_password(void){

	LCD_Clear();
	LCD_1st_Line();
	LCD_WriteSentence(" Enter Old Pass ");
	LCD_2nd_Line();
}


/* 	 Function    : print_enter_password
**   Parameters  : None
**   Return      : None
**   Description : it clears the LCD then prints " Enter Password " on LCD
*/
void print_enter_password(void){

	LCD_Clear();
	LCD_1st_Line();
	LCD_WriteSentence(" Enter Password ");
	LCD_2nd_Line();
}




/* 	 Function    : open_safe
**   Parameters  : None
**   Return      : None
**   Description : It will open the safe
*/
void open_safe(void){
	LCD_Clear();
	LCD_WriteSentence("  Safe  Opened  ");
	Stepper_SetDirection(CLOCKWISE);
	Stepper_Half_Revoloution();
}

/* 	 Function    : close_safe
**   Parameters  : None
**   Return      : None
**   Description : It will close the safe
*/
void close_safe(void){
	LCD_Clear();
	LCD_WriteSentence("  Safe  Closed  ");
	Stepper_SetDirection(COUNTER_CLOCKWISE);
	Stepper_Half_Revoloution();
}

/* 	 Function    : wait_in_second
**   Parameters  : time
**   Return      : None
**   Description : It will wait for user enter seconds
*/
void wait_in_second(UINT8 time){
	_delay_ms(1000*time);
}




/* 	 Function    : System_Init
**   Parameters  : None
**   Return      : None
**   Description : It will Initialize the system (LCD - Stepper - Keypad)
*/
void System_Init(void){

	LCD_Init();
	Keypad_Init();
	Stepper_Init();
	/******* Stepper will make half Revolution in 1 second *******/
	Stepper_Set_Time_Per_Revolution(2000); //takes time in milliSeconds
}



/* 	 Function    : remove_password_from_LCD
**   Parameters  : None
**   Return      : None
**   Description : It will remove the '*' on the LCD , put ' ' instead
*/
void remove_password_from_LCD(void){
	UINT8 i ;
	LCD_2nd_Line();

	for(i =0 ; i<NUMBER_OF_DIGITS_IN_PASSWORD;i++)
		LCD_WriteData(' ');

	LCD_2nd_Line();
}


void print_number_of_mistakes(UINT8 mistakes){
	if(mistakes==0)
	{
		LCD_Clear();
	    LCD_1st_Line();
		LCD_WriteSentence(" First mistake ");
	}
	else if(mistakes==1)
	{
		LCD_Clear();
	    LCD_1st_Line();
		LCD_WriteSentence(" second mistake ");
	}
	else
	{
		LCD_Clear();
		LCD_1st_Line();
		LCD_WriteSentence(" third mistake ");
	}
}

void print_invalid(UINT8 check_if_error)
{
	if(check_if_error==0)
	{
		LCD_Clear();
		LCD_1st_Line();
		LCD_WriteSentence(" wrong password ");
    }
}





