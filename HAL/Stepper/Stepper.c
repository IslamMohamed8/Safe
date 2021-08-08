#include "Stepper.h"

#include <util/delay.h>  // so i can use _dealy_ms() function





void Stepper_Init(){



}


void Stepper_SetSpeed(UINT8 speed){


}


void Stepper_SetDirection(UINT8 direction){
  
	int period;
	DDRD = 0x0F;		// Make PORTD lower pins as output
	period = 100;		// Set period in between two steps 
while (1)
	{
		// Rotate Stepper Motor clockwise with Half step sequence 
		for(int i=0;i<12;i++)
		{
			PORTD = 0x09;
			_delay_ms(period);
			PORTD = 0x08;
			_delay_ms(period);
			PORTD = 0x0C;
			_delay_ms(period);
			PORTD = 0x04;
			_delay_ms(period);
			PORTD = 0x06;
			_delay_ms(period);
			PORTD = 0x02;
			_delay_ms(period);
			PORTD = 0x03;
			_delay_ms(period);
			PORTD = 0x01;
			_delay_ms(period);
		}
		PORTD = 0x09;		// Last step to initial position  
		_delay_ms(period);
		_delay_ms(1000);

		// Rotate Stepper Motor Anticlockwise with Full step sequence
		for(int i=0;i<12;i++)
		{
			PORTD = 0x09;
			_delay_ms(period);
			PORTD = 0x03;
			_delay_ms(period);
			PORTD = 0x06;
			_delay_ms(period);
			PORTD = 0x0C;
			_delay_ms(period);
		}
		PORTD = 0x09;
		_delay_ms(period);
		_delay_ms(1000);
	}


}


void Stepper_Step(UINT8 steps){


}

