/*
 * Interrupt.c
 *
 * Created: 1/8/2023 9:35:09 PM
 *  Author: mehob
 */ 
#include "GEXTINT_interface.h"

static	void	(*EXTI_CallBack[16])	(void)	= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
//intrupt global enable
//input: void
//output :enum for function error state
//function:it enable the global intrrubts for the atemage32
EN_functionstate_t Intrupt_GlobalEnable(){
	sei();
	return Function_ok;

}
//intrupt global disable
//input:void
//output :enum for function error state
//function:it disable the global intrupts for the ATmega32
EN_functionstate_t Intrupt_globalDisabled(){
	cli();
	return Function_ok;
	}
//intrupt external sense
//input:External intrupt name ,Intrupt required mode
//output :enum for function error state
//function :it define the sense of the external intrupts
EN_functionstate_t Intrupt_ExternalSense(u8 EXTintruptnum,InterMode_t Intruptmode){
	switch (EXTintruptnum)
	{
		case EInt0:
			switch (Intruptmode)
			{
			case lowlevel:
				MCUCR &=~(0x03);		
				break;
			case Anylogic :
				MCUCR &=~(1<<1);
				MCUCR |=(1<<0);
				break;
			case FallingEdge:
				MCUCR &=~(1<<0);
				MCUCR |=(1<<1);
				break;
			case RisingEdge:
				MCUCR |=(0x03);;
				break;
			default:
				return Function_Error;	
			}
			return Function_ok;
			break;
		case EInt1:
			switch (Intruptmode)
			{
				case lowlevel:
				MCUCR &=~(0x0c);
				break;
				case Anylogic :
				MCUCR &=~(1<<3);
				MCUCR |=(1<<2);
				break;
				case FallingEdge:
				MCUCR &=~(1<<2);
				MCUCR |=(1<<3);
				break;
				case RisingEdge:
				MCUCR |=(0x0c);;
				break;
				default:
				return Function_Error;
			}
			return Function_ok;
			break;
		case EInt2:
			switch (Intruptmode)
			{
				case FallingEdge:
				MCUCSR &=~(1<<6);
				break;
				case RisingEdge:
				MCUCSR |=(1<<6);;
				break;
				default:
				return Function_Error;
			}
			return Function_ok;
			break;
		default:
			return Function_Error;
	}
}
//intrupt enable external
//input: required intrupt to enable
//output :enum for function error state
//function:it enable the required external intrupt
EN_functionstate_t Intrupt_EnableExternal(u8 EXTintruptnum){
	switch (EXTintruptnum)
	{
	case EInt0:
		GICR |=(1<<6);
		break;
	case EInt1:
		GICR |=(1<<7);
		break;
	case EInt2:
		GICR |=(1<<5);
		break;
	default:
		return Function_Error;
	}
	return Function_ok;
}
//intrupt disable external
//input: required intrupt to disable
//output :enum for function error state
//function:it disable the required external intrupt
EN_functionstate_t Intrupt_DisableExternal(u8 EXTintruptnum){
	switch (EXTintruptnum)
	{
		case EInt0:
		GICR &=~(1<<6);
		break;
		case EInt1:
		GICR &=~(1<<7);
		break;
		case EInt2:
		GICR &=~(1<<5);
		break;
		default:
		return Function_Error;
	}
	return Function_ok;
}
//intrupt external flag read
//input :name of the intrupt required to read and adrress of a variable to save the flag in
//output :enum for function error state
//function:read the intrupt flag and save it in the provided address of a variable
EN_functionstate_t Intrupt_ExtFlagRead(u8 EXTintruptnum,u8 *value){
	switch (EXTintruptnum)
	{
	case EInt0 :
		*value=(GIFR &(1<<6))>>6;
		GIFR|=(1<<6);
		break;
	case EInt1:
		*value=(GIFR &(1<<7))>>7;
		GIFR|=(1<<7);
		break;
	case EInt2:
		*value=(GIFR &(1<<5))>>5;
		GIFR|=(1<<5);
		break;
	default:
		return Function_Error;
	}
	return Function_ok;
}



void	EXTI_voidSetCallBack(void (*Fptr)(void), u8 ID_EXTI)
{
	if(Fptr != NULL)
	{
		EXTI_CallBack[ID_EXTI] = Fptr;
	}
}


ISR (EXTRINT0)
{

	if(EXTI_CallBack[EInt0] !=NULL){
		EXTI_CallBack[0]();
		CLR_BIT(GIFR,6);
	}
	//Clear the Flag
}

ISR (EXTRINT1)
{
	if(EXTI_CallBack[EInt1]!=NULL){
		EXTI_CallBack[1]();
		CLR_BIT(GIFR,7);
	}
	//Clear the Flag
}
 ISR (EXTRINT2)
{
	if(EXTI_CallBack[EInt2]!=NULL){
		EXTI_CallBack[2]();
		CLR_BIT(GIFR,5);
	}
}
/*

//intrupt function test
//input:void
//output:enum for driver error state
//function :calls all the apis of the intrupt driver and returns the state of the driver
EN_Driverstate_t Intrupt_test(){
	#define EXTINTNO EInt0
	#define INTRUPTMDE RisingEdge
	volatile u8 fg;
	if ( Intrupt_GlobalEnable()!= Function_ok)
	{
		return Driver_Error;
	} 
	else if ( Intrupt_GlobalEnable()!= Function_ok)
	{
		return Driver_Error;

	}else if (Intrupt_ExternalSense(EXTINTNO,INTRUPTMDE)!= Function_ok)
	{
		return Driver_Error;

	}else if ( Intrupt_EnableExternal(EXTINTNO)!= Function_ok)
	{
		return Driver_Error;
	}else if (Intrupt_ExtFlagRead(EXTINTNO,&fg)!= Function_ok)
	{
		return Driver_Error;

	}else if ( Intrupt_DisableExternal(EXTINTNO)!= Function_ok)
	{
		return Driver_Error;

	}else if ( Intrupt_globalDisabled()!= Function_ok)
	{
		return Driver_Error;
	} 
	else
	{
		return Driver_ok;
	}
		
}
	
	 */
	
	 
	 
	
