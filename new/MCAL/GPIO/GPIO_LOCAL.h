#ifndef GPIO_LOCAL_H_
#define GPIO_LOCAL_H_

#define PORTA *((volatile UINT8*)(0x3B))
#define DDRA *((volatile UINT8*)(0x3A))
#define PINA *((volatile UINT8*)(0x39))

#define PORTB *((volatile UINT8*)(0x38))
#define DDRB *((volatile UINT8*)(0x37))
#define PINB *((volatile UINT8*)(0x36))

#define PORTC *((volatile UINT8*)(0x35))
#define DDRC *((volatile UINT8*)(0x34))
#define PINC *((volatile UINT8*)(0x33))

#define PORTD *((volatile UINT8*)(0x32))
#define DDRD *((volatile UINT8*)(0x31))
#define PIND *((volatile UINT8*)(0x30))

#endif /* GPIO_LOCAL_H_ */
