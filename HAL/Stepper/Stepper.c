#include "Stepper.h"
static UINT8 DELAY_TIME = 100;// to be able to change time in (ms)

static UINT8 motor_direction = MOTOR_DIRECTION;


void Stepper_Init(){
#if MOTOR_TYPE == UNIPOLAR
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_A, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_B, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_C, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_D, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_E, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_F, OUTPUT);

#elif MOTOR_TYPE == BIPOLAR
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_A, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_B, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_C, OUTPUT);
	 GPIO_INIT_PIN_DIRECTION(MOTOR_PORT ,WINDING_D, OUTPUT);

#elif MOTOR_TYPE == UNIVERSAL

	GPIO_INIT_PORT_DIRECTION(MOTOR_PORT,OUTPUT);

#endif



}


void Stepper_SetSpeed(UINT8 speed)
{
	DELAY_TIME = (1/((STEPS_PER_REVOLUTION * speed)/60))*1000 ; // time in ms


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



void stepper_full_step(void)
{
        UINT8 j;
	UINT8 i=0;
	PORT_D=0x00; 


	while(1)
		{ 	
			// for full step clockwise
			for(j=0;j<360/N;j++) // assume steps of stepper motor = 7.5 degree  so for complete roll (360/7.5) 
			{
				PORT_D =(1<<i);  //starting from coil 1 to 2 to 3 to 4 
				i++;
				_delay_ms(100);
				
				if(i==4)
				i=0;
				
			}
			_delay_ms(1000);
			
			// for full step ANTI_CLOCKWISE
			for(j=0;j<360/N;j++)
					{
						PORT_D =(8>>i);  //starting from coil 4 to 3 to 2 to 1    8 decimal to 1000
						i++;
						_delay_ms(100);  //delay between two steps
						
						if(i==4)
						i=0;
						
					}
					_delay_ms(1000);
					
		}

}




void stepper_half_step(void)
{ 
		
	        UINT8 j;
		UINT8 i=0;
	
		
		while(1)
		{ 
	 
			/* Rotate Stepper Motor clockwise with Half step sequence */
				for(int i=0;i<360/N;i++)
				{ 
				PORT_D = 0x09;
				_delay_ms(period);
				PORT_D = 0x08;
				_delay_ms(period);
				PORT_D = 0x0C;
				_delay_ms(period);
				PORT_D = 0x04;
				_delay_ms(period);
				PORT_D = 0x06;
				_delay_ms(period);
				PORT_D = 0x02;
				_delay_ms(period);
				PORT_D = 0x03;
				_delay_ms(period);
				PORT_D = 0x01;
				_delay_ms(period);
				}
				PORT_D = 0x09; // Last step to initial position  
				_delay_ms(period);
				_delay_ms(1000);
				 
				/* Rotate Stepper Motor Anti_clockwise with half step sequence */
				for(int i=0;i<360/N;i++)
				{
					PORT_D = 0x01;
				_delay_ms(period);
				PORT_D = 0x03;
				_delay_ms(period);
				PORT_D = 0x02;
				_delay_ms(period);
				PORT_D = 0x06;
				_delay_ms(period);
				PORT_D = 0x04;
				_delay_ms(period);
				PORT_D = 0x0C;
				_delay_ms(period);
				PORT_D = 0x08;
				_delay_ms(period);
				PORT_D = 0x09;
				_delay_ms(period);
				 
				}
				PORT_D = 0x09;
				_delay_ms(period);
				_delay_ms(1000);
				}
			
}

void Stepper_Step(UINT8 steps)
{


}

