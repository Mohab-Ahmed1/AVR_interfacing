	
	
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

	//ADC interupt
	void read (void);
	u8 x =0;
	u32 number ;
	u32 celsius;
	int main (){
		LED_int(PORT_B,PIN7);
		LED_off(PORT_B,PIN7);
		DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
		seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
		
		Intrupt_GlobalEnable();
		ADC_voidSetCallBack(read);
		ADC_Intalize();
		ADC_SETADCMux_Mode(ADC_1);
		ADC_startconversion();
		while (1)
		{
			ADC_startconversion();
			ADC_SETADCMux_Mode(ADC_1);
			if(x==1){
				ADC_GETDATAvalue(&number);
				 celsius = (number*4.88);
				 celsius = (celsius/10.00);
				x=0;
			}
			seg_printDecoder4Num(celsius);
			ADC_EnableInterupt();
		}
		
	}
	void read (void){
		x=1;
		ADC_DisableInterupt ();
	}