/*
 * ADC_programing.c
 *
 * Created: 6/17/2023 9:32:02 AM
 *  Author: mehob
 */ 
#include "ADC_interfacing.h"
void ADC_Intalize(void){
	#if ADC_alligment == ADC_leftAllign
		{
			SET_BIT(ADMUX,5);
		}
	#elif ADC_alligment ==ADC_RightAllign
		{
			CLR_BIT(ADMUX,5);
		}
	#endif
	
	#if ADC_voltgerefrence	==	ADC_vref_off
		{
			CLR_BIT(ADMUX,7);//REFS1
			CLR_BIT(ADMUX,6);//REFS0
		}
	#elif	ADC_voltgerefrence	==	ADC_ExternCap
		{
			CLR_BIT(ADMUX,7);//REFS1
			SET_BIT(ADMUX,6);//REFS0
		}
	#elif	ADC_voltgerefrence	==	ADC_intvol_EXTcap
		{
			SET_BIT(ADMUX,7);//REFS1
			SET_BIT(ADMUX,6);//REFS0
		}
	#endif
	#if ADC_InteruptStatus	== ADC_INTEN
	ADC_EnableInterupt();
	
	#elif ADC_InteruptStatus	== ADC_INTDis
	ADC_DisableInterupt();
	#endif
	
	ADC_SETExteernalTrig ();
	ADC_SETprescaler();
	ADC_Enable();

	
}
//choose from			
/*	1-ADC_0,
	2-ADC_1,
	3-ADC_2,
	4-ADC_3,
	5-ADC_4,
	6-ADC_5,
	7-ADC_6	*/	
void ADC_SETADCMux_Mode(ADCMODE_t ADC_mode){
	
	if (ADC_mode==ADC_0)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		CLR_BIT(ADMUX,1);//mux1
		CLR_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_1)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		CLR_BIT(ADMUX,1);//mux1
		SET_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_2)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		SET_BIT(ADMUX,1);//mux1
		CLR_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_3)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		SET_BIT(ADMUX,1);//mux1
		SET_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_4)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		SET_BIT(ADMUX,2);//mux2
		CLR_BIT(ADMUX,1);//mux1
		CLR_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_5)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		SET_BIT(ADMUX,2);//mux2
		CLR_BIT(ADMUX,1);//mux1
		SET_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_6)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		SET_BIT(ADMUX,2);//mux2
		SET_BIT(ADMUX,1);//mux1
		CLR_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC_7)
	{
		CLR_BIT(ADMUX,4);//mux4
		CLR_BIT(ADMUX,3);//mux3
		SET_BIT(ADMUX,2);//mux2
		SET_BIT(ADMUX,1);//mux1
		SET_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC0_ADC0_10x)
	{
		CLR_BIT(ADMUX,4);//mux4
		SET_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		CLR_BIT(ADMUX,1);//mux1
		CLR_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC1_ADC0_10x)
	{
		CLR_BIT(ADMUX,4);//mux4
		SET_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		CLR_BIT(ADMUX,1);//mux1
		SET_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC0_ADC0_200x)
	{
		CLR_BIT(ADMUX,4);//mux4
		SET_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		SET_BIT(ADMUX,1);//mux1
		CLR_BIT(ADMUX,0);//mux0
	}else if (ADC_mode==ADC1_ADC0_200x)
	{
		CLR_BIT(ADMUX,4);//mux4
		SET_BIT(ADMUX,3);//mux3
		CLR_BIT(ADMUX,2);//mux2
		SET_BIT(ADMUX,1);//mux1
		SET_BIT(ADMUX,0);//mux0
	}
	
}
void ADC_Enable(void){
	SET_BIT(ADCSRA,7);//ADEN
}
void ADC_DIsable(void){
		CLR_BIT(ADCSRA,7);//ADEN
}
void ADC_startconversion (void){
	SET_BIT(ADCSRA,6); //ADSC

	#if ADC_InteruptStatus	== ADC_INTDis
	while (GET_BIT(ADCSRA,4)==0) {
		// Wait for the conversion to complete
	}
	
	#endif
	

    
ADC_clearFlag();
}
void ADC_SETExteernalTrig (void){
	#if ADC_TriggerSource == ADC_swtriger
	{
		CLR_BIT(SFIOR,7);//ADTs2
		CLR_BIT(SFIOR,6);//ADTs1
		CLR_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_AnalogCompartor
	{
		SET_BIT(ADCSRA,5);//Adata
		CLR_BIT(SFIOR,7);//ADTs2
		CLR_BIT(SFIOR,6);//ADTs1
		SET_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_EXTINT0
	{
		SET_BIT(ADCSRA,5);//Adata
		CLR_BIT(SFIOR,7);//ADTs2
		SET_BIT(SFIOR,6);//ADTs1
		CLR_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_TIMER0compM
	{
		CLR_BIT(SFIOR,7);//ADTs2
		SET_BIT(SFIOR,6);//ADTs1
		SET_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_Timer0overflow
	{
		SET_BIT(ADCSRA,5);//Adata
		SET_BIT(SFIOR,7);//ADTs2
		CLR_BIT(SFIOR,6);//ADTs1
		CLR_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_TIMER1compMB
	{
		SET_BIT(ADCSRA,5);//Adata
		SET_BIT(SFIOR,7);//ADTs2
		CLR_BIT(SFIOR,6);//ADTs1
		SET_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_Timer1overflow
	{
		SET_BIT(ADCSRA,5);//Adata
		SET_BIT(SFIOR,7);//ADTs2
		SET_BIT(SFIOR,6);//ADTs1
		CLR_BIT(SFIOR,5);//ADTs0
		
	}
	#elif  ADC_TriggerSource == ADC_Timer1CaptureEvent
	{
		SET_BIT(ADCSRA,5);//Adata
		SET_BIT(SFIOR,7);//ADTs2
		SET_BIT(SFIOR,6);//ADTs1
		SET_BIT(SFIOR,5);//ADTs0
		
	}
	#endif
	
	
	
}
void ADC_GETFlag(u8 *flag){
	*flag=GET_BIT(ADCSRA,4);//ADif
}
void ADC_clearFlag(void){
	SET_BIT(ADCSRA,4);//ADIF
	CLR_BIT(ADCSRA,6);
}
void ADC_EnableInterupt(void){
	SET_BIT(ADCSRA,3);//ADIE
}
void ADC_DisableInterupt (void){
	CLR_BIT(ADCSRA,3);//ADIE
}
void ADC_SETprescaler(void){
	#if ADC_prescaler == ADC_Divide2
	{
		CLR_BIT(ADCSRA,2);//ADPS2
		CLR_BIT(ADCSRA,1);//ADPS1
		CLR_BIT(ADCSRA,0);//ADPS0
	}
	#elif ADC_prescaler == ADC_Divide4
	{
		CLR_BIT(ADCSRA,2);//ADPS2
		SET_BIT(ADCSRA,1);//ADPS1
		CLR_BIT(ADCSRA,0);//ADPS0
	}
	#elif ADC_prescaler == ADC_Divide8
	{
		CLR_BIT(ADCSRA,2);//ADPS2
		SET_BIT(ADCSRA,1);//ADPS1
		SET_BIT(ADCSRA,0);//ADPS0
	}
	#elif ADC_prescaler == ADC_Divide16
	{
		SET_BIT(ADCSRA,2);//ADPS2
		CLR_BIT(ADCSRA,1);//ADPS1
		CLR_BIT(ADCSRA,0);//ADPS0
	}
	#elif ADC_prescaler == ADC_Divide32
	{
		SET_BIT(ADCSRA,2);//ADPS2
		CLR_BIT(ADCSRA,1);//ADPS1
		SET_BIT(ADCSRA,0);//ADPS0
	}
	#elif ADC_prescaler == ADC_Divide64
	{
		SET_BIT(ADCSRA,2);//ADPS2
		SET_BIT(ADCSRA,1);//ADPS1
		CLR_BIT(ADCSRA,0);//ADPS0
	}
	#elif ADC_prescaler == ADC_Divide128
	{
		SET_BIT(ADCSRA,2);//ADPS2
		SET_BIT(ADCSRA,1);//ADPS1
		SET_BIT(ADCSRA,0);//ADPS0
	}
	#endif

	
}
void ADC_GETDATAvalue(u16 *Data){
	
	#if ADC_alligment == ADC_leftAllign
		{
			*Data=(ADCH << 8) | ADCL;
		}
	#elif ADC_alligment == ADC_RightAllign
	{
		*Data =ADCHL;
		
	}
	#endif
}
static	void	(*ADC_CallBack)	(void)	= NULL;
void		ADC_voidSetCallBack(void (*Fptr)(void))
{

	if(Fptr != NULL)
	{
		ADC_CallBack = Fptr ;
	}
}
ISR(ADCINT){
	ADC_CallBack();
	
}