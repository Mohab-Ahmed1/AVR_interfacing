/*
 * Timer.h
 *
 * Created: 1/8/2023 9:33:05 PM
 *  Author: mehob
 */ 


#ifndef TIMER_Interface_H_
#define TIMER_Interface_H_
//**all Includes
#include "../../00 LIB/Bit_Math.h"
#include "../../00 LIB/Std_Types.h"
#include "Timer_config.h"
#include "Timer_private.h"
//###########################
//************timer driver
//all macros for the timer drier
#define Timer_0 0
#define Timer_1 1
#define Timer_2 2

typedef enum Timermode_t{  //wgm01
	Normal,Ctc,pwm,fastpwm
}Timermode_t;

//compare out modes   //comp01
#define Comp_Normal 0
#define Toogle_oco_oR_reserved 1
#define clear_oco_oncompare	2
#define SET_oco_oncompare 3

// timer intrupt modes
#define TOIE 0
#define OCIE 1
//timer reading flags
#define TOV 0
#define OCF 1
//####################################


//***ALL functions prototype
//Timer mode function
//input:timer number,timer mode number,timer compare out mode number
//output :enum for function error state
//function :this function sets for the required timer ,its mode &compare out mode
EN_functionstate_t Timer_mode(u8 timernumber,Timermode_t mode,u8 compareoutmode);
//timer inatial value function
//input:timer number & inatial value required to set
//output :enum for function error state
//function :this function sets for the required timer the inatial value to start counting from
EN_functionstate_t Timer_InatialVal(u8 timernumber,u8 intvalue);
//timer set compare value
//input:timer number & compare value required to set
//output :enum for function error state
//function:this function sets the compare value for the specified timer
EN_functionstate_t Timer_CompareVal(u8 timernumber,u8 compvalue);
//timer intrupt enable
//input:timer number ,intrupt mode required to set
//output :enum for function error state
//function: it enable the required intrupt mode for the specified timer
EN_functionstate_t Timer_intruptEnable(u8 timernumber,u8 Intruptmodee);
//timer intrupt disable
//input:timer number ,intrupt mode required to set
//output :enum for function error state
//function:it disable the required intrupt mode for the specified timer
EN_functionstate_t Timer_intruptDisable(u8 timernumber,u8 Intruptmodee);
//timer start & setingprescale value
//input:timer number & prescalemode
//output :enum for function error state
//function:it sets the prescaler value for therequired timer letting it to start
EN_functionstate_t Timer_StartPRESCalerValue(u8 timernumber,u8 prescalermodes);
//timer read a flag
//input:timernumber ,timer flag ,address for the variable to save the flag
//output :enum for function error state
//function:it reads the required flag from a specific timer and returns it to an address
EN_functionstate_t Timer_ReadFlag(u8 timernumber,u8 timerflag,u8 *read);

//timer clear flags
//input:timernumber ,timer flag 
//output: enum for function error state
//function: this function erases the required flag from its register 
EN_functionstate_t Timer_EraseFlag(u8 timernumber,u8 timerflag);

EN_functionstate_t TIMER0_callbackfunc(void (*Fptr)(void), u8 timerID,u8 Mode);
//timer test function
//input:void
//output :enum for driver error state
//function: it calls all the apis of the drivers and returns driiver_ok if all the apis functioned ok 
EN_Driverstate_t Timer_Test();
#endif /* TIMER_Interface_H_ */