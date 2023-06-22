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


int main (){
	
	u16 number =0;
	u16 voltage=0;

	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
	//seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	LCD_4_bit_intalize();
	
	
	Intrupt_GlobalEnable();
	ADC_Intalize();
	ADC_SETADCMux_Mode(ADC_0);
	
	
	while (1)
	{
		
		ADC_SETADCMux_Mode(ADC_0);
		ADC_startconversion();
		ADC_GETDATAvalue(&number);
		LCD_4_bit_sendcommand(clear_display);
		_delay_ms(1);
		Lcd_4_bit_courserposition(1,0);
		Lcd_4_bit_sendstring("voltmetermode");
		Lcd_4_bit_courserposition(2,0);
		 voltage = number/204.8*18;
		 voltage=((4400)/(89))*voltage;
		Lcd_4_bit_sendnumber(voltage);
		Lcd_4_bit_sendstring("mvolt");
		//seg_printDecoder4Num(number);
		LED_toogle(PORT_B,PIN7);
		ADC_clearFlag();
		_delay_ms(500);
	}
	
}
