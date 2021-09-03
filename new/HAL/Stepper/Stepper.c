#include "Stepper.h"
#include "../../LIB/UTILES.h"
#include "../../MCAL/GPIO/GPIO.h"
#include <util/delay.h>

static UINT8 motor_direction = MOTOR_DIRECTION;
static UINT8 delay_ms = 100;


static void Stepper_Move_4Steps_Clockwise(void);
static void Stepper_Move_4Steps_CounterClockwise(void);


void Stepper_Init(){

#if MOTOR_TYPE == UNIPOLAR
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,PIN0, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,PIN1, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,PIN2, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,PIN3, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,PIN4, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,PIN5, OUTPUT);

#elif MOTOR_TYPE == BIPOLAR
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_A, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_B, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_C, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_D, OUTPUT);

#elif MOTOR_TYPE == UNIVERSAL

	GPIO_INIT_PORT_DIRECTION(MOTOR_PORT,OUTPUT);

#endif

}


void Stepper_Set_Time_Per_Revolution(UINT16 time_ms){
	delay_ms = time_ms / STEPS_PER_REVOLUTION; // time in milliseconds

}




void Stepper_SetDirection(UINT8 direction){

	switch(direction){
	case CLOCKWISE:
		motor_direction = CLOCKWISE;
		break;
	case COUNTER_CLOCKWISE:
		motor_direction = COUNTER_CLOCKWISE;
		break;
	}


}



void Stepper_Half_Revoloution(void){
	UINT8 i ;
	UINT8 x = STEPS_PER_REVOLUTION >> 3; //Divided by 8

	if(motor_direction == CLOCKWISE){

		for(i = 0;i<x;i++){
		/******* move 4 steps every iteration *******/
			Stepper_Move_4Steps_Clockwise();
		}

	}
	else if (motor_direction == COUNTER_CLOCKWISE){

		for(i = 0;i<x;i++){
		/******* move 4 steps every iteration *******/
			Stepper_Move_4Steps_CounterClockwise();
		}

	}

}

void Stepper_Full_Revoloution(void){
	UINT8 i ;
	UINT8 x = STEPS_PER_REVOLUTION >> 2; //Divided by 4

	if(motor_direction == CLOCKWISE){

		for(i = 0;i<x;i++){
		/******* move 4 steps every iteration *******/
			Stepper_Move_4Steps_Clockwise();
		}

	}
	else if (motor_direction == COUNTER_CLOCKWISE){

		for(i = 0;i<x;i++){
		/******* move 4 steps every iteration *******/
			Stepper_Move_4Steps_CounterClockwise();
		}

	}


}

static void Stepper_One_Step_Clockwise(void){


}

static void Stepper_One_Step_CounterClockwise(void){


}


#if MOTOR_TYPE == BIPOLAR
void Stepper_Steps(UINT8 steps){
	UINT8 i ;

	if(motor_direction == CLOCKWISE){

		for(i = 0;i<steps;i++)
		  Stepper_One_Step_Clockwise();
		}
   else if(motor_direction == COUNTER_CLOCKWISE){
		for(i = 0;i<steps;i++)
		  Stepper_One_Step_CounterClockwise();
		}
}

static void Stepper_Move_4Steps_Clockwise(void){
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,HIGH);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);
	_delay_ms(delay_ms);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,HIGH);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);
	_delay_ms(delay_ms);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,HIGH);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);
	_delay_ms(delay_ms);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,HIGH);
	_delay_ms(delay_ms);
}

static void Stepper_Move_4Steps_CounterClockwise(void){

	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,HIGH);
	_delay_ms(delay_ms);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,HIGH);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);
	_delay_ms(delay_ms);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,HIGH);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);
	_delay_ms(delay_ms);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_A,HIGH);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_B,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_C,LOW);
	GPIO_WRITE_PIN_VALUE(MOTOR_PORT,WINDING_D,LOW);
	_delay_ms(delay_ms);
}



#elif MOTOR_TYPE == UNIPOLAR
void Stepper_Step(UINT8 steps){

}

static void Stepper_Move_4Steps_Clockwise(void){

}

static void Stepper_Move_4Steps_CounterClockwise(void){

}

#elif MOTOR_TYPE == UNIVERSAL
void Stepper_Step(UINT8 steps){}

static void Stepper_Move_4Steps_Clockwise(void){

}

static void Stepper_Move_4Steps_CounterClockwise(void){

}

#endif



