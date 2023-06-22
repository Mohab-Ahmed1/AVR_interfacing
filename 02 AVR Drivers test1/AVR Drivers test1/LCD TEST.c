
#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"


int main(void)
{

	LCD_4_bit_intalize();
	Lcd_4_bit_sendstring("////////////////////");
	Lcd_4_bit_sendstring("/       bonous      /");
	Lcd_4_bit_courserposition(2,0);
	Lcd_4_bit_sendstring("/        hello     /");
	Lcd_4_bit_sendstring("////////////////////");
	
	_delay_ms(1000);
	
	char text1[] = "////////////////////"; // The first line of text to scroll
	char text2[] = "/       bonous     /"; // The second line of text to
	char text3[] = "/        hello     /"; 
	char text4[] = "////////////////////"; 
		u16 x=0,j=20 ;
		//Lcd_4_bit_courserposition(1,19);
		u16 iCursor =0;
		int iLenofLargeText = 20;
	u16	iLineNumber=3;
	while (1)
	{
		LCD_4_bit_sendcommand(display_shiftleft);
		_delay_ms(1000);
		/*
		//LCD_4_bit_sendcommand(cursor_shiftleft);
	//Lcd_4_bit_courserposition(1,j);
	LCD_4_bit_sendchar(text2[19-x]);
	x++;
	
	if(x==19){
		x=0;
	}*/
	
	//LCD_4_bit_sendcommand(display_shiftleft);
	/*
	if ( iCursor== (iLenofLargeText - 1)) // Reset variable for rollover effect.
	{
		iCursor=0;
	}

	Lcd_4_bit_courserposition ( iLineNumber,0);
	if ( iCursor < iLenofLargeText -16) //this loop exicuted for normal 16 Character
	{
		for ( int iChar = iCursor; iChar < iCursor + 16; iChar++){
			LCD_4_bit_sendchar( text2 [iChar]); //print a massage to the LCD,
		}
		
	}else
	{
		for (int iChar = iCursor; iChar<( iLenofLargeText - 1); iChar++){
			// This code takes care of printing charecters of current string.
			LCD_4_bit_sendchar (text2 [iChar]); //print a massage to the LCD.
			
		}
		for (int iChar = 0; iChar < 16 - (iLenofLargeText- iCursor); iChar++){
			//Reaminig Charecter will be printed by this loop
			LCD_4_bit_sendchar (text2 [iChar]); //print the massage to the LCD
		}
		
	}
	iCursor++;
	*/
	
}
	}
	
	
