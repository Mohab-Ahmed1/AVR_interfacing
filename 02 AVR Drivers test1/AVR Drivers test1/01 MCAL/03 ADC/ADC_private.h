

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
#define ADCINT  __vector_16

#  define __INTR_ATTRS used
#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

#define ADMUX *((volatile u8*)0x27) //8 bit register to write data //&& pull up in case input
#define ADCSRA *((volatile u8*)0x26) //8 bit register to set the pin direction
#define ADCL *((volatile u8*)0x24) //8 bit register to read the pin status
#define ADCH *((volatile u8*)0x25) //8 bit register to read the pin status

#define SFIOR *((volatile u8*)0x50) //8 bit register to read the pin status

#define ADCHL        *((volatile u16*)0x24)

#endif /* ADC_PRIVATE_H_ */