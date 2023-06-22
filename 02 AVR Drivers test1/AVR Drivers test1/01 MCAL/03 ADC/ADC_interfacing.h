
#ifndef ADC_INTERFACING_H_
#define ADC_INTERFACING_H_
#include "../../00 LIB/Bit_Math.h"
#include "../../00 LIB/Std_Types.h"

#include "ADC_config.h"
#include "ADC_private.h"
//refrence selection 

#define ADC_vref_off  50
#define	ADC_ExternCap  51//at the AREF pin 
#define	ADC_intvol_EXTcap 52
	

//alighment choose

#define	ADC_leftAllign 53
#define	ADC_RightAllign 54

//choose the channel 
typedef enum  {
			ADC_0,
			ADC_1,
			ADC_2,
			ADC_3,
			ADC_4,
			ADC_5,
			ADC_6,
			ADC_7,
			ADC0_ADC0_10x,
			ADC1_ADC0_10x,
			ADC0_ADC0_200x,
			ADC1_ADC0_200x
			}ADCMODE_t;
//choose the triger source		

#define ADC_swtriger 55
#define	ADC_AnalogCompartor 56
#define	ADC_EXTINT0 57
#define	ADC_TIMER0compM 58
#define	ADC_Timer0overflow 59
#define	ADC_TIMER1compMB 60
#define	ADC_Timer1overflow 61
#define	ADC_Timer1CaptureEvent 62
	
//choose the prescaler

#define	ADC_Divide2 63
#define	ADC_Divide4 64
#define	ADC_Divide8 65 
#define	ADC_Divide16 66 
#define	ADC_Divide32 67
#define	ADC_Divide64 68
#define	ADC_Divide128 69


//choose the intrupt status

#define	ADC_INTEN 70
#define	ADC_INTDis 71
	
void ADC_Intalize(void);
//choose from			
/*	1-ADC_0,
	2-ADC_1,
	3-ADC_2,
	4-ADC_3,
	5-ADC_4,
	6-ADC_5,
	7-ADC_6	
	8-ADC_7,
	9-ADC0_ADC0_10x,
	10-ADC1_ADC0_10x,
	11-ADC0_ADC0_200x,
	12-ADC1_ADC0_200x*/	
void ADC_SETADCMux_Mode(ADCMODE_t ADC_mode);
void ADC_Enable(void);
void ADC_DIsable(void);
void ADC_startconversion (void);
void ADC_SETExteernalTrig (void);//in intalize
void ADC_GETFlag(u8 *flag);
void ADC_clearFlag(void);//instartup conv
void ADC_EnableInterupt(void);
void ADC_DisableInterupt (void); 
void ADC_SETprescaler(void);//in intalizer
void ADC_GETDATAvalue(u16 *Data);
int ADC_Read(char channel);
void	ADC_voidSetCallBack(void (*Fptr)(void));
#endif /* ADC_INTERFACING_H_ */