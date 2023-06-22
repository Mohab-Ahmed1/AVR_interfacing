/*
 * Interrupt.c
 *
 * Created: 1/8/2023 9:35:09 PM
 *  Author: mehob
 */ 
#include "GIE_interface.h"
//intrupt global enable
//input: void
//output :enum for function error state
//function:it enable the global intrrubts for the atemage32
EN_functionstate_t GIE_IntruptGlobalEnable(){
	sei();
	return Function_ok;

}
//intrupt global disable
//input:void
//output :enum for function error state
//function:it disable the global intrupts for the ATmega32
EN_functionstate_t GIE_IntruptGlobalDisabled(){
	cli();
	return Function_ok;
	}
	
	 
	
	 
	 
	
