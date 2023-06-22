#include "01 MCAL/00 DIO driver/DIO_interface.h"
#include "01 MCAL/01 GINTRUPT/GEXTINT_interface.h"
#include "01 MCAL/02 GIE/GIE_interface.h"
#include "02 ECUAL/00 LED/LED_interfce.h"
#include "02 ECUAL/01 7segment/7segment_interface.h"
#include "02 ECUAL/02 LCD/lCD_interface.h"
#include "02 ECUAL/03 KEYPAD/KEYPAD_interface.h"
#include "02 ECUAL/04 BUZZER/Buzzer_interfce.h"
#include "02 ECUAL/05 Button/button_Interface.h"

void inc (void);

void RES (void);
u8 count=0;
int main(void)
{
	
	LED_int(PORT_B,PIN7);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	
 Intrupt_GlobalEnable();
 
 //exti1 intrupt
  BUTTON_init(PORT_D,3,Button_pullup);
 Intrupt_ExternalSense(EInt1,RisingEdge);
 Intrupt_EnableExternal(EInt1);
 EXTI_voidSetCallBack(inc,EInt1);
 //etin0 intrupt
 BUTTON_init(PORT_D,2,Button_pullup);
  Intrupt_ExternalSense(EInt0,RisingEdge);
  Intrupt_EnableExternal(EInt0);
  EXTI_voidSetCallBack(RES,EInt0);
  
  
	while(1){
		seg_printDecoder4Num(count);
	}
	}
	
	void RES (void){
		count=0;
		LED_off(PORT_B,PIN7);
		_delay_ms(100);
	}
void inc (void){
	
	count++;
	LED_on(PORT_B,PIN7);
	_delay_ms(100);
	
}	
