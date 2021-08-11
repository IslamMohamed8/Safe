#ifndef STEPPER_H_
#define STEPPER_H_

#include "Stepper_CONF.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/UTILES.h"

void Stepper_Init();
void Stepper_SetSpeed(UINT8 speed);
void Stepper_SetDirection(UINT8 direction);
void Stepper_Step(UINT8 steps);



void stepper_full_step(void);
void stepper_half_step(void);


#endif /* STEPPER_H_ */
