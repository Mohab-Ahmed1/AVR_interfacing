


#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

//##################################################################
//*************interrupt driver macro
//macros defined for interrupts
//enable global interrupt
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
//disable global interrupt
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")






#endif /* EXTI_INTERFACE_H_ */