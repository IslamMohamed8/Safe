#include "Stepper.h"





void Stepper_Init(){



}


void Stepper_SetSpeed(UINT8 speed){


}


void Stepper_SetDirection(UINT8 direction){


}


void Stepper_Step(UINT8 steps) 
{
  UINT8 j;
	UINT8 i=0;
	PORT_D=0x00; 
	while(1)
	{
		for(j=0;j<48;j++) // assume steps of stepper motor = 7.5 degree  so for complete roll (360/7.5)= 48
		{
			PORT_D =(1<<i);  //starting from coil 1 to 2 to 3 to 4 
			i++;
			_delay_ms(100);
			
			if(i==4)
			i=0;
			
		}
		_delay_ms(5000);
		
		for(j=0;j<48;j++)
				{
					PORT_D =(8>>i);  //starting from coil 4 to 3 to 2 to 1    8 decimal to 1000
					i++;
					_delay_ms(100);  //delay between two steps
					
					if(i==4)
					i=0;
					
				}
				_delay_ms(5000);
				
	}



}

