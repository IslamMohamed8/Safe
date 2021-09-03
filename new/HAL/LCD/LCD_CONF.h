#ifndef LCD_CONF_H_
#define LCD_CONF_H_

#include "../../MCAL/GPIO/GPIO_CONFIG.h"

/********************************* define control and data Pins    *******************************************/
#define RS_PORT  PORT_B
#define RS_PIN   4
#define RW_PORT  PORT_B
#define RW_PIN   5
#define EN_PORT  PORT_B
#define EN_PIN   6
#define LCD_PORT  PORT_A

/**********************************    LCD standard commands   ****************************************/
#define LCD_4BIT_1_LINE_5_x_7              0x20
#define LCD_4BIT_2_LINE_5_x_7              0x28
#define LCD_8BIT_1_LINE_5_x_7              0x30
#define LCD_8BIT_2_LINE_5_x_7              0x38
#define LCD_ENTRY_MODE                     0x06
#define LCD_DISPLAY_OFF_CURSOR_OFF         0x08
#define LCD_DISPLAY_ON_CURSOR_ON           0x0E
#define LCD_DISPLAY_ON_CURSOR_OFF          0x0C
#define LCD_DISPLAY_ON_CURSOR_BLINKING     0x0F
#define LCD_DISPLAY_SHIFT_ENTIRE_LEFT      0x18
#define LCD_DISPLAY_SHIFT_ENTIRE_RIGHT     0x1C
#define LCD_MOVE_CURSOR_LEFT_ONE_CHAR      0x10
#define LCD_MOVE_CURSOR_RIGHT_ONE_CHAR     0x14
#define LCD_CLEAR_ALSO_DDRAM               0x01
#define FORCE_CURSOR_TO_BEGINNING_1ST_LINE 0x80
#define FORCE_CURSOR_TO_BEGINNING_2ND_LINE 0xC0

/******************************************************************************************************/


#endif
