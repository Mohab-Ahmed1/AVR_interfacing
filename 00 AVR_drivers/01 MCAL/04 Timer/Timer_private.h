/*
 * Timer_private.h
 *
 * Created: 6/18/2023 11:21:02 AM
 *  Author: mehob
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

//timer2 comp match Intrupt Request
#define Timer2CompINT __vector_4
//timer 2 over flow intrupt request
#define Timer2OvfINT __vector_5
//timer 0 comp match intrupt request
#define Timer0CompINT __vector_10
//timer 0 over flow intrupt request
#define  Timer0OvfINT __vector_11


#  define __INTR_ATTRS used
#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)
//timer0
/*
typedef struct  
		{
			u8 CS:3;
			u8 WGM01:1;
			u8 COM :2;
			u8 WGM00:1;
			u8 FOC0 :1;
		} TCCRO_reg;
	#define TCCR0 *((volatile TCCRO_reg*)0x53);	

*/

//***timer registers
//timer 0
#define TCCR0 *((volatile u8*)0x53) //8 bit register define timer status (mode +prescaler_that starts the timer when defined _)
#define TCNT0 *((volatile u8*)0x52) //8 bit register to define the intial value of the timer
#define TIFR *((volatile u8*)0x58) //8 bit register to read the flags of the timer OCIE0 ,TOIE0
#define TIMSK *((volatile u8*)0x59) //8 bit register to enable the intrupt TOIE0 (over flow ) & OCF0 (compare intrupt )
#define  OCR0 *((volatile u8*)0x5C) //8bit register that contain the value we compare with current value to allow the compare flag

//timer 2
#define TCCR2 *((volatile u8*)0x45) //8 bit register define timer status (mode +prescaler_that starts the timer when defined _)
#define TCNT2 *((volatile u8*)0x44) //8 bit register to define the intial value of the timer
#define TIFR *((volatile u8*)0x58) //8 bit register to read the flags of the timer intrups OCIE2 ,TOIE2
#define TIMSK *((volatile u8*)0x59) //8 bit register to enable the intrupt TOIE2 (over flow ) & OCF2 (compare intrupt )
#define  OCR2 *((volatile u8*)0x43) //8bit register that contain the value we compare with current value to allow the compare flag
#define  ASSR *((volatile u8*)0x42) //8bit register that contain the value we compare with current value to allow the compare flag


//timer 1
#define TCCR1A *((volatile u8*)0x4f)
#define TCCR1B *((volatile u8*)0x4E)

#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)
#define TCNT1	*((volatile u16*)0x4C)

#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)
#define OCR1A	*((volatile u16*)0x4A)

#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
#define OCR1B	*((volatile u16*)0x48)

#define ICR1H *((volatile u8*)0x47)
#define ICR1L *((volatile u8*)0x46)
#define ICR1 *((volatile u16*)0x46)

#endif /* TIMER_PRIVATE_H_ */