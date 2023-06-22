

#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"

#define dely 500
int main(void)
{
	u16 i=0;
	//sleep hamoksha
	u8 Character1[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b01000,
		0b10100,
		0b11000,
		0b10010,
		0b11101
	};
	//wakeup hamoksha
	u8 Character2[8] = {
		0b00000,
		0b00000,
		0b01110,
		0b01110,
		0b10101,
		0b01110,
		0b00100,
		0b01010
	};
	//hamoksha push up
	u8 Character3[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b01110,
		0b01010,
		0b11111,
		0b10001,
		0b10001
	};
	//hamoksh push down
	u8 Character4[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b01110,
		0b11011,
		0b10101
	};
	//car
	u8 Character5[8] = { //stairs
		0b00000,
		0b00000,
		0b00000,
		0b01110,
		0b01010,
		0b11111,
		0b11111,
		0b10001
	};
	//hamoksha walk 1
	u8 Character6[8] = {
		0b00100,
		0b01010,
		0b00100,
		0b00110,
		0b00101,
		0b00100,
		0b01010,
		0b10010
	};
	//hamoksha walk 2
	u8 Character7[8] = {
		0b00100,
		0b01010,
		0b00100,
		0b01100,
		0b10100,
		0b00100,
		0b01010,
		0b01001
	};

	//gym
	u8 Character8[8] = {
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b00000,
		0b10001,
		0b11111,
		0b10001
	};

	
	
	
	LCD_4_bit_intalize();
	Lcd_4_bit_createcustomchar( Character1,0);//sleep hamoksha
	Lcd_4_bit_createcustomchar( Character2,1);//wakeup hamoksha
	Lcd_4_bit_createcustomchar( Character3,2);//hamoksha push up
	Lcd_4_bit_createcustomchar( Character4,3);//hamoksh push down
	Lcd_4_bit_createcustomchar( Character5,4);//car
	Lcd_4_bit_createcustomchar( Character6,5);//hamoksha walk 1
	Lcd_4_bit_createcustomchar( Character7,6);//hamoksha walk 2
	Lcd_4_bit_createcustomchar( Character8,7);//gym
	
	//###################################################
	LCD_4_bit_sendcommand(cursor_firstline);
	Lcd_4_bit_sendstring("Home");
	Lcd_4_bit_courserposition(2,0);
	Lcd_4_bit_printCustomChar(0);
	_delay_ms(dely);
	Lcd_4_bit_courserposition(2,0);
	Lcd_4_bit_printCustomChar(1);
	_delay_ms(dely);
	Lcd_4_bit_courserposition(2,0);
	Lcd_4_bit_printCustomChar(0);
	_delay_ms(dely);
	Lcd_4_bit_courserposition(2,0);
	Lcd_4_bit_printCustomChar(1);
	_delay_ms(dely);
	
	//walk
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(5);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(6);	
	_delay_ms(dely);

	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(5);
	_delay_ms(dely);

	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(6);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(4,i);
	Lcd_4_bit_printCustomChar(5);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(4,i);
	Lcd_4_bit_printCustomChar(6);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(4,i);
	Lcd_4_bit_printCustomChar(5);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(4,i);
	Lcd_4_bit_printCustomChar(6);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	
	//get in car
	i=i+2;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(4,i);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(4,i);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(3,i);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(2,i);
	Lcd_4_bit_printCustomChar(4);
	_delay_ms(dely);
	//walk again 
	
	
	i++;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(1);
	Lcd_4_bit_courserposition(2,i);
	Lcd_4_bit_printCustomChar(1);
	_delay_ms(dely);
	
	while (1)
	{
		
		LCD_4_bit_sendcommand(clear_display);
		_delay_ms(1);
		Lcd_4_bit_courserposition(1,16);
		Lcd_4_bit_sendstring("Gym");
		Lcd_4_bit_courserposition(2,16);
		Lcd_4_bit_printCustomChar(2);
		Lcd_4_bit_printCustomChar(7);
		
		_delay_ms(dely);
		
		
		LCD_4_bit_sendcommand(clear_display);
		_delay_ms(1);
		Lcd_4_bit_courserposition(1,16);
		Lcd_4_bit_sendstring("Gym");
		Lcd_4_bit_courserposition(2,16);
		Lcd_4_bit_printCustomChar(3);
		Lcd_4_bit_printCustomChar(7);
		_delay_ms(dely);
	}
	
}
