#ifndef __KEYPAD_CONFIG_H__
#define __KEYPAD_CONFIG_H__

#include "../../MCAL/GPIO/GPIO_CONFIG.h"
/******************************************************************
*                       Pins &  Keypad Symbols                    *
******************************************************************/

#define KEYPAD_ARRAY   		       {'7','8','9','D'},\
				       {'4','5','6','M'},\
				       {'1','2','3','N'},\
				       {'C','0','=','P'}


#define KEYPAD_PORT PORT_C
#define R1_PIN 0
#define R2_PIN 1
#define R3_PIN 2
#define R4_PIN 3
#define C1_PIN 4
#define C2_PIN 5
#define C3_PIN 6
#define C4_PIN 7


#define COL 4
#define ROW 4

#define ROW_INT 0
#define ROW_END 3
#define COL_INT 4
#define COL_END 7





#endif
