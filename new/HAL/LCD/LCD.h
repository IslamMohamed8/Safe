#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONF.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/UTILES.h"

void LCD_Init(void);
void LCD_WriteData(UINT8 Character);
void LCD_WriteSentence(UINT8 *PtrSentance);
void LCD_Clear(void);
void LCD_1st_Line(void);
void LCD_2nd_Line(void);

#endif
