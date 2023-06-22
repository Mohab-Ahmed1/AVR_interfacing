/*
 * Interrupt.h
 *
 * Created: 1/8/2023 9:34:55 PM
 *  Author: mehob
 */ 


#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_
#include "../../00 LIB/Bit_Math.h"
#include "../../00 LIB/Std_Types.h"
#include "GIE_config.h"
#include "GIE_private.h"


//###############################################################################

//all functions prototypes
//interrupt global enable
//input: void
//output :enum for function error state
//function:it enable the global interrupts for the atemage32
EN_functionstate_t GIE_IntruptGlobalEnable(); //sei()
//interrupt global disable
//input:void
//output :enum for function error state
//function:it disable the global interrupts for the ATmega32
EN_functionstate_t GIE_IntruptGlobalDisabled(); //cli()



#endif /* GIE_INTERFACE_H_ */