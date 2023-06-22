/*
 * ADC_config.h
 *
 * Created: 6/17/2023 9:33:38 AM
 *  Author: mehob
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
//choose from 
/*
1- ADC_vref_off,
2-ADC_ExternCap,//at the AREF pin
3-ADC_intvol_EXTcap*/
#define ADC_voltgerefrence		ADC_ExternCap

//choose from
/*
	1-ADC_leftAllign,
	2-ADC_RightAllign*/
#define ADC_alligment	ADC_RightAllign
//choose from 
/*
1-ADC_swtriger,
2-ADC_AnalogCompartor,
3-ADC_EXTINT0,
4-ADC_TIMER0compM,
5-ADC_Timer0overflow,
6-ADC_TIMER1compMB,
7-ADC_Timer1overflow,
8-ADC_Timer1CaptureEvent
*/
#define ADC_TriggerSource	ADC_swtriger
//choose from
/*
1-ADC_Divide2,
2-ADC_Divide4,
3-ADC_Divide8,
4-ADC_Divide16,
5-ADC_Divide32,
6-ADC_Divide64,
7-ADC_Divide128*/

#define ADC_prescaler	ADC_Divide128
//choose from
/*
1-ADC_INTEN
2-ADC_INTDis*/
#define ADC_InteruptStatus	ADC_INTEN
#endif /* ADC_CONFIG_H_ */