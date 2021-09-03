#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/UTILES.h"
#include "../../MCAL/GPIO/GPIO.h"


#define NO_KEY_IS_PRESSED  250

/*************************** Functions ***************************/
void Keypad_Init(void);
UINT8 Keypad_GetKey(void);


#endif
