#ifndef STEPPER_H_
#define STEPPER_H_

#include "Stepper_CONF.h"
#include "../../LIB/STD_TYPES.h"


void Stepper_Init(void);
void Stepper_Set_Time_Per_Revolution(UINT16 time_ms);
void Stepper_SetDirection(UINT8 direction);
void Stepper_Steps(UINT8 steps);
void Stepper_Half_Revoloution(void);
void Stepper_Full_Revoloution(void);

#endif /* STEPPER_H_ */
