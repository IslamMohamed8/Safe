#ifndef GPIO_H_
#define GPIO_H_

#include "../../LIB/STD_TYPES.h"

void GPIO_INIT_PORT_DIRECTION(UINT8 PORT , UINT8 DIRECTION);
void GPIO_WRITE_PORT_VALUE(UINT8 PORT , UINT8 VALUE);
UINT8 GPIO_READ_PORT_VALUE(UINT8 PORT);

void GPIO_INIT_PIN_DIRECTION(UINT8 PORT ,UINT8 PINno, UINT8 DIRECTION);
void GPIO_WRITE_PIN_VALUE(UINT8 PORT ,UINT8 PINno , UINT8 VALUE);
UINT8 GPIO_READ_PIN_VALUE(UINT8 PORT ,UINT8 PINno);
void GPIO_TOGGLE_PIN(UINT8 PORT ,UINT8 PINno);

#endif /* GPIO_H_ */
