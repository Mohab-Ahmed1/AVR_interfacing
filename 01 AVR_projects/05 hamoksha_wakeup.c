
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

	

int main(void)
{	u8 number=0;
	
	u8 flag=0;

	u8 Character1[8] = {
		 0b00100,
		 0b01010,
		 0b01010,
		 0b10101,
		 0b01110,
		 0b00100,
		 0b01010,
		 0b10001
	 };
	u8 Character2[8] = {
		0b00000,
		0b00000,
		0b01000,
		0b10100,
		0b10100,
		0b01000,
		0b01010,
		0b01101
	};

	LCD_4_bit_intalize();
	
	Lcd_4_bit_createcustomchar( Character1,0);
	Lcd_4_bit_createcustomchar( Character2,1);
	LCD_4_bit_sendcommand(cursor_firstline);
/*
	Lcd_4_bit_printCustomChar(0);
	Lcd_4_bit_printCustomChar(1);*/
	
	DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
	//seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);	
	
	//adc intalize 
	ADC_Intalize();
	
	while (1)
	{
		ADC_SETADCMux_Mode(ADC_0);
		ADC_startconversion();
		ADC_GETDATAvalue(&number);
		
		
		if(number > 100 &&flag==0){
			LCD_4_bit_sendcommand(cursor_firstline);
			//Lcd_4_bit_sendnumber(number);
			Lcd_4_bit_printCustomChar(1);
			flag=1;
			
		}
		if (number<100 &&flag==1)
		{
			LCD_4_bit_sendcommand(cursor_firstline);
			//Lcd_4_bit_sendnumber(number);
			Lcd_4_bit_printCustomChar(0);
			flag=0;
			
		}
		
		//seg_printDecoder4Num(number);
		
		ADC_clearFlag();
		
		
	}
}

