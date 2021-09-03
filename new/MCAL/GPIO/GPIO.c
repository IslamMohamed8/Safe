#include "../../LIB/STD_TYPES.h"
#include "../../LIB/UTILES.h"
#include "GPIO_LOCAL.h"
#include "GPIO_CONFIG.h"
#include "GPIO.h"

void GPIO_INIT_PORT_DIRECTION(UINT8 PORT , UINT8 DIRECTION)
{
	
	if(DIRECTION == OUTPUT)
	  DIRECTION = 0xFF;
	else if(DIRECTION == INPUT)
	  DIRECTION = 0x00; 
	   
	switch(PORT){
	case PORT_A:
	ASSIGNPORT(DDRA , DIRECTION);
	break;
	case PORT_B:
	ASSIGNPORT(DDRB , DIRECTION);
	break;
	case PORT_C:
	ASSIGNPORT(DDRC , DIRECTION);
	break;
	case PORT_D:
	ASSIGNPORT(DDRD , DIRECTION);
	break;
	default:
	
	break;
	}
}

void GPIO_WRITE_PORT_VALUE(UINT8 PORT , UINT8 VALUE)
{

switch(PORT){
	case PORT_A:
	ASSIGNPORT(PORTA , VALUE);
	break;
	case PORT_B:
	ASSIGNPORT(PORTB , VALUE);
	break;
	case PORT_C:
	ASSIGNPORT(PORTC , VALUE);
	break;
	case PORT_D:
	ASSIGNPORT(PORTD , VALUE);
	break;
	default:
	
	break;
	}

}

UINT8 GPIO_READ_PORT_VALUE(UINT8 PORT)
{
	UINT8 VALUE;
	
	switch(PORT){
	case PORT_A:
	VALUE = GETPORT(PINA);
	break;
	case PORT_B:
	VALUE = GETPORT(PINB);
	break;
	case PORT_C:
	VALUE = GETPORT(PINC);
	break;
	case PORT_D:
	VALUE = GETPORT(PIND);
	break;
	default:
	VALUE = GETPORT(PINA);
	break;
	}
	
	return VALUE;
}

void GPIO_INIT_PIN_DIRECTION(UINT8 PORT ,UINT8 PINno, UINT8 DIRECTION)
{
switch(PORT){
	case PORT_A:
	ASSIGNBIT(DDRA , PINno , DIRECTION);
	break;
	case PORT_B:
	ASSIGNBIT(DDRB , PINno , DIRECTION);
	break;
	case PORT_C:
	ASSIGNBIT(DDRC , PINno , DIRECTION);
	break;
	case PORT_D:
	ASSIGNBIT(DDRD , PINno , DIRECTION);
	break;
	default:
	
	break;
	}

}

void GPIO_WRITE_PIN_VALUE(UINT8 PORT ,UINT8 PINno , UINT8 VALUE)
{
	switch(PORT){
	case PORT_A:
	ASSIGNBIT(PORTA , PINno , VALUE);
	break;
	case PORT_B:
	ASSIGNBIT(PORTB , PINno , VALUE);
	break;
	case PORT_C:
	ASSIGNBIT(PORTC , PINno , VALUE);
	break;
	case PORT_D:
	ASSIGNBIT(PORTD , PINno , VALUE);
	break;

	}
}

UINT8 GPIO_READ_PIN_VALUE(UINT8 PORT ,UINT8 PINno)
{
	UINT8 PIN;
	
	switch(PORT){
	case PORT_A:
	 PIN = GETBIT(PINA , PINno);
	break;
	case PORT_B:
	 PIN = GETBIT(PINB , PINno);
	break;
	case PORT_C:
	 PIN = GETBIT(PINC , PINno);
	break;
	case PORT_D:
	 PIN = GETBIT(PIND , PINno);
	break;
	default:
	 PIN = GETBIT(PINA , PINno);
	break;
	}
	
	return PIN;
}

void GPIO_TOGGLE_PIN(UINT8 PORT ,UINT8 PINno){

	switch(PORT){
	case PORT_A:
		TOGGLEBIT(PORTA ,PINno );
	break;
	case PORT_B:
		TOGGLEBIT(PORTB ,PINno );
	break;
	case PORT_C:
		TOGGLEBIT(PORTC ,PINno );
	break;
	case PORT_D:
		TOGGLEBIT(PORTD ,PINno );
	break;

	}
}

