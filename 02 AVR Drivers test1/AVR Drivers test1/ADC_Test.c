
#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "01 MCAL/01 GINTRUPT/GEXTINT_interface.h"
#include "01 MCAL/02 GIE/GIE_interface.h"
#include "01 MCAL/03 ADC/ADC_interfacing.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"

/*

//ADC source triggered  by EXTI0
void read (void);
void RES (void);
u8 x =0;
u16 number ;
int main (){	
	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	Intrupt_GlobalEnable();
	
	 //etin0 intrupt
	 BUTTON_init(PORT_D,2,Button_pullup);
	 Intrupt_ExternalSense(EInt0,RisingEdge);
	 Intrupt_EnableExternal(EInt0);
	 EXTI_voidSetCallBack(RES,EInt0);
	 //adc intalize
	ADC_voidSetCallBack(read);
	ADC_Intalize();
	ADC_SETADCMux_Mode(ADC_0);
	ADC_startconversion();
	while (1)
	{
		//ADC_startconversion();
		ADC_SETADCMux_Mode(ADC_0);
		if(x==1){
			ADC_GETDATAvalue(&number);
			x=0;
		}
		seg_printDecoder4Num(number);
		ADC_EnableInterupt();
	}
	
}
void read (void){
	x=1;
	ADC_DisableInterupt ();
}
void RES (void){
	//count=0;
	LED_off(PORT_B,PIN7);
	_delay_ms(100);
}
*/

 
 
 /*
 	//ADC interupt
 	void read (void);
 	u8 x =0;
 	u32 number ;
 	int main (){

	 	LED_int(PORT_B,PIN7);
	 	LED_off(PORT_B,PIN7);
	 	DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
	 	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	 	
	 	ADC_voidSetCallBack(read);
	 	Intrupt_GlobalEnable();
	 	ADC_Intalize();
	 	ADC_SETADCMux_Mode(ADC_0);
	 	ADC_startconversion();
	 	while (1)
	 	{
		 	ADC_startconversion();
		 	ADC_SETADCMux_Mode(ADC_0);
		 	if(x==1){
			 	ADC_GETDATAvalue(&number);
			 	x=0;
		 	}
		 	seg_printDecoder4Num(number);
		 	ADC_EnableInterupt();
	 	}
	 	
 	}
 	void read (void){
	 	x=1;
	 	ADC_DisableInterupt ();
 	}
*/



 //ADC_polling
		 
 int main (){
	
	 u16 number =0;
	

	 LED_int(PORT_B,PIN7);
	  LED_off(PORT_B,PIN7);
	 DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
	 seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	 
	 Intrupt_GlobalEnable();
	 ADC_Intalize();
	 ADC_SETADCMux_Mode(ADC_0);
	
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
	




