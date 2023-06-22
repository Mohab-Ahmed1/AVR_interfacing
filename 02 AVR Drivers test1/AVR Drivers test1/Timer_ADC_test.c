#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "01 MCAL/01 GINTRUPT/GEXTINT_interface.h"
#include "01 MCAL/02 GIE/GIE_interface.h"
#include "01 MCAL/03 ADC/ADC_interfacing.h"
#include "01 MCAL/04 Timer/Timer_Interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"



// sevensegment count ldr
void led_blink (void);
u16 counter=0;
int main (){
	u16 number =0;
	u8 flag=0;
	
	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	ADC_Intalize();
	ADC_SETADCMux_Mode(ADC_0);
	
	
	Timer_mode(Timer_0,Normal,5);
	Timer_InatialVal(Timer_0,0x00);
	Intrupt_GlobalEnable();
	
	Timer_mode(Timer_0,fastpwm,clear_oco_oncompare);
	Timer_CompareVal(Timer_0,0x3f);
	Timer_StartPRESCalerValue(Timer_0,5);
	
	
	while (1)
	{
		ADC_SETADCMux_Mode(ADC_0);
		ADC_startconversion();
		ADC_GETDATAvalue(&number);
		if(number>100 &&flag==0){
			counter++;
			flag=1;
		}
		if (number<100 &&flag==1)
		{flag=0;
		}
		seg_printDecoder4Num(counter);
		
		LED_toogle(PORT_B,PIN7);
		ADC_clearFlag();
		
		
	}
}



/*

//ldr control led
void led_blink (void);
u8 counter=0;
int main (){
	u16 number =0;
	u8 flag=0;
	u16 val;
	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	ADC_Intalize();
	ADC_SETADCMux_Mode(ADC_0);
	
	
	Timer_mode(Timer_0,Normal,5);
	Timer_InatialVal(Timer_0,0x00);
	Intrupt_GlobalEnable();
	
	Timer_mode(Timer_0,fastpwm,clear_oco_oncompare);
	Timer_CompareVal(Timer_0,0x3f);
	Timer_StartPRESCalerValue(Timer_0,5);
	
	
	while (1)
	{
		ADC_SETADCMux_Mode(ADC_0);
		ADC_startconversion();
		ADC_GETDATAvalue(&number);
		val=((number-43)*(9-0))/(43-5);
		
		//Timer_CompareVal(Timer_0,0xff/val);
		Timer_CompareVal(Timer_0,0x00+(0x0f*val));
      seg_printDecoder4Num(val);
		LED_toogle(PORT_B,PIN7);
		ADC_clearFlag();
		
		
	}
}*/



/*

//timer0_interupt

void led_blink (void);
u8 counter=0;
int main (){
	 u16 number =0;
	 u8 flag=0;
	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	ADC_Intalize();
	ADC_SETADCMux_Mode(ADC_0);
	
	
	Timer_mode(Timer_0,Normal,5);
	Timer_InatialVal(Timer_0,0x00);
	Intrupt_GlobalEnable();
	Timer_intruptEnable(Timer_0,TOIE);
	Timer_StartPRESCalerValue(Timer_0,5);
	
	while (1)
	{
		  ADC_SETADCMux_Mode(ADC_0);
		  ADC_startconversion();
		  ADC_GETDATAvalue(&number);
		  seg_printDecoder4Num(number);
		  LED_toogle(PORT_B,PIN7);
		  ADC_clearFlag();
		
		
	}
}

*/
