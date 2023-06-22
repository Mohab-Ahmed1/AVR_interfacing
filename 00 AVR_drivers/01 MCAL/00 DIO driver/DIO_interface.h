


#ifndef DIO_interfce_H_
#define DIO_interfce_H_
//**all Includes
#include "../../00 LIB/Bit_Math.h"
#include "../../00 LIB/Std_Types.h"

#include "DIO_private.h"
#include "DIO_config.h"
//ports macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction macros
#define IN 0
#define OUT 1

//value macros
#define LOW 0
#define HIGH 1


//pins configration 
#define  PIN0  0
#define  PIN1  1
#define  PIN2  2
#define  PIN3  3
#define  PIN4  4
#define  PIN5  5
#define  PIN6  6
#define  PIN7  7

//all functions prototypes
//input: port number ,pinnumber,direction
//output: enum error state EN_functionstate_t
//function:intalize the direction of pins
EN_functionstate_t DIO_VoidSetPinDirection(u8 portnumber ,u8 pinnumber,u8 direction);
//input: port number ,pinnumber,value
//output: enum error state EN_functionstate_t
//function:write data on dio pin
EN_functionstate_t DIO_SETPinValue(u8 portnumber ,u8 pinnumber,u8 value);
 //input: port number ,pinnumber
 //output: enum error state EN_functionstate_t
 //function:toggle data on dio pin
EN_functionstate_t DIO_tooglePinValue(u8 portnumber ,u8 pinnumber); 
//input: port number ,pinnumber,address to value
//output: enum error state EN_functionstate_t
//function: read data on dio pin
EN_functionstate_t DIO_GetpinValueread (u8 portnumber ,u8 pinnumber,u8 *value);

EN_functionstate_t DIO_SetPortVlue (u8 portnumber,u8 value);
EN_functionstate_t DIo_SetPortDirection (u8 portnumber ,u8 direction);

//test  DIO_functions
//input: void
//output: enum error state EN_Driverstate_t
//function: it calls all the apis of the driver and return the driver state 
//EN_Driverstate_t DIO_Test(void);



#endif /* DIO_interfce_H_ */