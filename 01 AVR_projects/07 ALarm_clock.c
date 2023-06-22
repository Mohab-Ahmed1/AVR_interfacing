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

//timer0_interupt
void Time_count (void);
u8 counter =0;
u8 click='N';
u8 stage_counter=0;
u8 minuits=00;
u8 secands =00;
u8 timer_flag=0;
int main (){
	u8 i=0;
	u8 time [6];

	//buzzer intalize 
	Buzzer_int(PORT_C,PIN6);
	Buzzer_off(PORT_C,PIN6);
	Intrupt_GlobalEnable();
	
	//keypad intalize
	KEYPAD_Voidinit();
	//lcd intalize
	LCD_4_bit_intalize();
//timer that overflow every secand	
	Timer_mode(Timer_0,Normal,0);
	Timer_InatialVal(Timer_0,0x00);
	Timer_intruptEnable(Timer_0,TOIE);
	TIMER0_callbackfunc(Time_count,Timer_0,TOIE);
	//Timer_StartPRESCalerValue(Timer_0,5);//start counter
	
	Lcd_4_bit_sendstring("lcd_off" );
	
	while (1)
	{
			KEYPAD_Getpressedkey(&click);
			
			if (click=='c')
			{ LCD_4_bit_sendcommand(clear_display);
				_delay_ms(1);
				Lcd_4_bit_sendstring("lcd_Off" );
				click='N';
				stage_counter=0;
				i=0;
				Timer_StartPRESCalerValue(Timer_0,0);
				Buzzer_off(PORT_C,PIN6);
			}
			
			if (stage_counter==0 && click =='=' ) 
			{
				LCD_4_bit_sendcommand(clear_display);
				_delay_ms(1);
				Lcd_4_bit_sendstring("lcd_ON" );
				click='N';
				stage_counter=1;
			}else if (stage_counter>0 && stage_counter<6 && click!= 'N')
			{
				stage_counter++;
				
				Lcd_4_bit_courserposition(2,i);
				LCD_4_bit_sendchar(click);
				time[i]=click-'0';
				i++;
				click='N';
			}else if (stage_counter==6)
			{
				minuits=time[0]*10+time[1];
				secands=time[3]*10+time[4];
				
				
				stage_counter++;
			}else if (stage_counter==7 && click =='='){
				
			Timer_StartPRESCalerValue(Timer_0,5);	
			stage_counter++;
			}else if (stage_counter==8 && timer_flag==1)
			{
				timer_flag=0;
				if (minuits==0 && secands==0)
				{
					stage_counter=9;
					Timer_StartPRESCalerValue(Timer_0,0);
				}else{
					if (secands==0)
					{ minuits--;
						secands=60;
					}
				
					secands--;
					
					Timer_EraseFlag(Timer_0,TOV);
					LCD_4_bit_sendcommand(clear_display);
					_delay_ms(1);
					Lcd_4_bit_courserposition(1,0);
					Lcd_4_bit_sendstring("lcd_ON" );
					Lcd_4_bit_courserposition(2,0);
					Lcd_4_bit_sendnumber(minuits);
					LCD_4_bit_sendchar(':');
					Lcd_4_bit_sendnumber(secands);
				}
			}else if (stage_counter==9 )
			{ 
				Buzzer_on(PORT_C,PIN6);
				
			}
			
			
		
		
		
		
		
		
	}
	
	
}


void Time_count (void){
	counter++;
if (counter==1){
counter=0;
timer_flag=1;
	}
}
