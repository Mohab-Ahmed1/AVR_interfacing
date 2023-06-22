

#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"


int main(void)
{
	
	u8 Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };
	u8 Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
	u8 Character3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
	u8 Character4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
	u8 Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
	u8 Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
	u8 Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
	u8 Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

	LCD_4_bit_intalize();
	
	Lcd_4_bit_createcustomchar( Character1,0);
	Lcd_4_bit_createcustomchar( Character2,1);
	Lcd_4_bit_createcustomchar( Character3,2);
	Lcd_4_bit_createcustomchar( Character4,3);
	Lcd_4_bit_createcustomchar( Character5,4);
	Lcd_4_bit_createcustomchar( Character6,5);
	Lcd_4_bit_createcustomchar( Character7,6);
	Lcd_4_bit_createcustomchar( Character8,7);
	LCD_4_bit_sendcommand(cursor_firstline);
	Lcd_4_bit_sendstring("mohab");
	Lcd_4_bit_printCustomChar(0);
	Lcd_4_bit_printCustomChar(1);		
	Lcd_4_bit_printCustomChar(2);	
	Lcd_4_bit_printCustomChar(3);
	Lcd_4_bit_printCustomChar(4);
	Lcd_4_bit_printCustomChar(5);
	Lcd_4_bit_printCustomChar(6);
	Lcd_4_bit_printCustomChar(7);
	//Lcd_4_bit_sendnumber(32);

//Lcd_4_bit_sendstring("Enter password ");
    while (1) 
    {
			
		}
}