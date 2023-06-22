#ifndef DIO_privte_H_
#define DIO_privte_H_



//macros for port A
#define PORTA *((volatile u8*)0x3B) //8 bit register to write data //&& pull up in case input
#define DDRA *((volatile u8*)0x3A) //8 bit register to set the pin direction
#define PINA *((volatile u8*)0x39) //8 bit register to read the pin status

//macros for port b
#define PORTB *((volatile u8*)0x38) //8 bit register to write data//&& pull up in case input
#define DDRB *((volatile u8*)0x37) //8 bit register to set the pin direction
#define PINB *((volatile u8*)0x36) //8 bit register to read the pin status

//macros for port c
#define PORTC *((volatile u8*)0x35) //8 bit register to write data//&& pull up in case input
#define DDRC *((volatile u8*)0x34) //8 bit register to set the pin direction
#define PINC *((volatile u8*)0x33) //8 bit register to read the pin status

//macros for port d
#define PORTD *((volatile u8*)0x32) //8 bit register to write data//&& pull up in case input
#define DDRD *((volatile u8*)0x31) //8 bit register to set the pin direction
#define PIND *((volatile u8*)0x30) //8 bit register to read the pin status


#endif