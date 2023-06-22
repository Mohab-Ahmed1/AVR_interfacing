

//#include <avr/io.h>


#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"


int main(void)
{

	u8 x= 'N';
	u8 password[]= "12345";
	u8 input[sizeof(password)+1];
	u8 i=0;
	u8 input_counter=0;
	u8 error_counter=0;
	u8 errflg=0;
KEYPAD_Voidinit();
LCD_4_bit_intalize();
Buzzer_int(PORT_C,PIN6);
Buzzer_off(PORT_C,PIN6);
		while (1)
		{
			LCD_4_bit_sendcommand(clear_display);
			_delay_ms(1);
			Lcd_4_bit_sendstring("Enter password ");
			
//###################################################################			
			while (1)//task1 take user input 
			{
				KEYPAD_Getpressedkey(&x);
				
				if(x!='N' ){
						if(input_counter==sizeof(password)-1)
						{
							x='N';
							break;
						}
						
					LCD_4_bit_sendchar(x);
					input[input_counter]=x;
					
					input_counter++;
					x='N';
					
				
					
				}
			}
			
			
//###################################################################			
			while (1)//task2 compare the input with the password  
			{
				
				for ( i = 0; i < sizeof(password)-1; i++) {
					if (input[i] != password[i]) {
						
						error_counter++;
						Lcd_4_bit_sendnumber(error_counter);
						errflg=1;	
						break;
					}
					}
					
				if (errflg==0)
				{
					error_counter=0;
				}
					
				
					break;
			}
//###################################################################
			//task 3 clear the current status 
			while (1)
			{
				if (error_counter==0){
					LCD_4_bit_sendcommand(clear_display);
					_delay_ms(1);
					Lcd_4_bit_sendstring("welcome");
					
					break;
				}else if(error_counter<3){
					LCD_4_bit_sendcommand(clear_display);
					_delay_ms(1);
					Lcd_4_bit_sendstring("try again");
					Lcd_4_bit_sendnumber(error_counter);
					errflg=0;
					break;
				} else if (error_counter==3)
				{
					LCD_4_bit_sendcommand(clear_display);
					_delay_ms(1);
					Lcd_4_bit_sendstring("Itruder");
					Buzzer_on(PORT_C,PIN6);
					errflg=0;
					break;
				}
				
				
				
					
			}
			
//###################################################################
			
			//task4 reset the system 
			while(1){
				
				KEYPAD_Getpressedkey(&x);
				
				if(x!='N' && x=='c'){
					
						x='N';
						input_counter=0;
						Buzzer_off(PORT_C,PIN6);
						break;	
										
				}
			}
				
			
		}







   /* while (1) 
    {	
		KEYPAD_Getpressedkey(&x);
		if(x!='N' ){
				//Lcd_4_bit_sendstring(x);
				
				LCD_4_bit_sendchar(x);
				input[input_counter]=x;
				x='N';
			input_counter++;
			
		}
		
	
	if(input_counter ==sizeof(password)-1 ){
		for ( i = 0; i < sizeof(password); i++) {
			if (input[i] != password[i]) {
				input_counter=0;
				error_counter++;
				
				LCD_4_bit_sendcommand(clear_display);
				Lcd_4_bit_sendstring("try again");
				
				break;
				}
			}
			
		if (i == sizeof(password)-1) {
			Lcd_4_bit_courserposition(3,0);
			LCD_4_bit_sendcommand(clear_display);
			Lcd_4_bit_sendstring("welcome");
			input_counter=0;
			error_counter=0;
				}
				
			}
			
			if (error_counter==3)
			{
				Buzzer_on(PORT_C,PIN6);
			}
			
			
		}*/
}

