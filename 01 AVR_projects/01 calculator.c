

#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"


int main(void)
{
	/*
	u8 customChar[7] = {
		0x01,
		0x18,
		0x04,
		0x12,
		0x04,
		0x08,
		0x04,
		0x00
	};
	
	LCD_4_bit_intalize();
	//Lcd_4_bit_sendstring("mohab");
	Lcd_4_bit_createcustomchar(customChar, 1);
	Lcd_4_bit_printCustomChar(1);
	//Lcd_4_bit_sendnumber(32);
*/
	u8 x= 'N';
	u8 input_counter=0;
	u8 oper='N';
	u32 first=0,sec=0 , res =0;
KEYPAD_Voidinit();
LCD_4_bit_intalize();
Buzzer_int(PORT_C,PIN6);
Buzzer_off(PORT_C,PIN6);

//Lcd_4_bit_sendstring("Enter password ");
    while (1) 
    {
		
		KEYPAD_Getpressedkey(&x);
		if (x=='c')
		{ LCD_4_bit_sendcommand(clear_display);
			input_counter=0;
		}
		
		if(x!='N' && x!='c'  ){
				if (input_counter==0)
				{
					x=x-'0';
					Lcd_4_bit_sendnumber(x);
					first=x;
					
				}else if (input_counter==1){
					oper=x;
					LCD_4_bit_sendchar(x);
				}else if (input_counter==2){
					x=x-'0';
				Lcd_4_bit_sendnumber(x);
				sec=x;
				}else if (input_counter==3)
				{
					LCD_4_bit_sendchar(x);
					
				}
				x='N';
				input_counter++;
		}
		if (input_counter==4)
		{
			switch (oper)
			{
				case '+': Lcd_4_bit_sendnumber (first+sec);		input_counter=0; break;
				case '-': Lcd_4_bit_sendnumber (first-sec ); 	input_counter=0; break;
				case '*':
				res = first * sec;
				 Lcd_4_bit_sendnumber (res );	input_counter=0; break;
				case '/': Lcd_4_bit_sendnumber (first/sec ); 	input_counter=0;break;
				
			}
			
		}
		
		
	
			
		}
}