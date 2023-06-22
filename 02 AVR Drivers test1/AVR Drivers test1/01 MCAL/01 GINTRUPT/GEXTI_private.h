


#ifndef GEXTI_private_H_
#define GEXTI_private_H_


//*******External intrupt registers
#define MCUCR *((volatile u8*)0x55) //8 bit register define the intrupt sense of INT0 ,INT1
#define MCUCSR *((volatile u8*)0x54) //8 bit register define the intrupt sense of INT2
#define GIFR *((volatile u8*)0x5A) //8 bit register define the intrupt enable for INT0 ,INT1 ,INT2
#define GICR *((volatile u8*)0x5B) //8 bit register define  the intrupt general flag of INT0 ,INT1 ,INT2
#define SREG *((volatile u8*)0x5f)  //set pin 7  to enable nesting intrupt



#endif /* GEXTI_private_H_ */