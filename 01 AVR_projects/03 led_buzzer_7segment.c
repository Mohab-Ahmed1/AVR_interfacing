
#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "01 MCAL/01 GINTRUPT/GEXTINT_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"


int main(void)
{
	LED_int(PORT_B,PIN7);
	BUTTON_init(PORT_D,PIN7,Button_pullup);
	BUTTON_init(PORT_D,PIN5,Button_pullup);
	BUTTON_init(PORT_D,PIN3,Button_pullup);
	Buzzer_int(PORT_C,PIN6);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
//seg_printDecoderNum(0);
//DIO_SETPinValue(ENPort1,ENPin1,LOW);
	
	u8 buzz=1,led=1,Inc=1,Dec=1;
	u32 counter=0;
	seg_printDecoderNum(1);
	while (1)
	{
		
		BUTTON_read(PORT_D,PIN7,&led);
		BUTTON_read(PORT_D,PIN6,&buzz);
		BUTTON_read(PORT_D,PIN5,&Inc);
		BUTTON_read(PORT_D,PIN3,&Dec);
		
		if (Inc==0)
		{
			counter++;
			
			_delay_ms(200);
			Inc=1;
		}
		if (Dec==0)
		{
			counter--;
			
			_delay_ms(200);
			Dec=1;
		}
		
		if (led==0)
		{
			LED_toogle(PORT_B,PIN7);
			_delay_ms(200);
			led=1;
		}
		
		if (buzz==0)
		{
			
		Buzzer_toogle(PORT_C,PIN6);
			_delay_ms(200);
			buzz=1;
		}
		
		seg_printDecoder4Num(counter);
	
	}
}