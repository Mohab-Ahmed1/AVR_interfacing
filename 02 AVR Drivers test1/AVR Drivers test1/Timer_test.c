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


/*
 // timer 1 led blink
int main(){
	
	
	DIO_VoidSetPinDirection(PORT_D,PIN5,OUT);

	//choose clear on compare for chanel A
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	//chhose waveform generrator for channelA
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);


	//set the compare value for duty cycle
	OCR1A=100;
	
	//set the iCR value for the top indication
	ICR1=1250;
	DIO_VoidSetPinDirection(PORT_D,PIN5,HIGH);

	//choose prescaler
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	while (1)
	{
		
	}
	
}*/















/*
//song pwm timer 0
void led_blink (void);
void inc (void);
u8 counter =0;
u8 click=0;
int main (){
	LED_int(PORT_B,PIN7);
	LED_on(PORT_B,PIN7);
	Buzzer_int(PORT_C,PIN6);
	Buzzer_on(PORT_B,PIN7);
	DIO_VoidSetPinDirection(PORT_B,PIN3,OUT);
	Intrupt_GlobalEnable();
	

	KEYPAD_Voidinit();
	Timer_mode(Timer_0,fastpwm,clear_oco_oncompare);
	Timer_CompareVal(Timer_0,0x3f);
	Timer_StartPRESCalerValue(Timer_0,5);
	
	while (1)
	{
		KEYPAD_Getpressedkey(&click);
		
		if (click=='1')
		{
			Timer_CompareVal(Timer_0,0xff/1);
		}else if (click=='2'){
			Timer_CompareVal(Timer_0,0xff/2);
		}else if (click=='3'){
		Timer_CompareVal(Timer_0,0xff/3);
		}else if (click=='4'){
	Timer_CompareVal(Timer_0,0xff/4);
		}else if (click=='5'){
Timer_CompareVal(Timer_0,0xff/5);
		}else if (click=='6'){
Timer_CompareVal(Timer_0,0xff/6);
		}else if (click=='7'){
Timer_CompareVal(Timer_0,0xff/7);
		}else if (click=='8'){
Timer_CompareVal(Timer_0,0xff/8);
		}else if (click=='9'){
Timer_CompareVal(Timer_0,00);
	}
		
	}
}*/

/*
//keybad_fastpwm_timer0
void led_blink (void);
void inc (void);
u8 counter =0;
u8 click=0;
int main (){
	LED_int(PORT_B,PIN7);
	LED_on(PORT_B,PIN7);
	Buzzer_int(PORT_C,PIN6);
	Buzzer_on(PORT_B,PIN7);
	DIO_VoidSetPinDirection(PORT_B,PIN3,OUT);
	Intrupt_GlobalEnable();
	
	
	Timer_mode(Timer_0,fastpwm,clear_oco_oncompare);
	//Timer_InatialVal(Timer_0,0x00);
	Timer_CompareVal(Timer_0,0x3f);
	
	
	KEYPAD_Voidinit();
	
	
	Timer_StartPRESCalerValue(Timer_0,5);
	
	while (1)
	{
		KEYPAD_Getpressedkey(&click);
		
		if (click=='1')
		{
			Timer_CompareVal(Timer_0,0xff/1);
		}else if (click=='2'){
			Timer_CompareVal(Timer_0,0xff/2);
		}else if (click=='3'){
		Timer_CompareVal(Timer_0,0xff/3);
		}else if (click=='4'){
	Timer_CompareVal(Timer_0,0xff/4);
		}else if (click=='5'){
Timer_CompareVal(Timer_0,0xff/5);
		}else if (click=='6'){
Timer_CompareVal(Timer_0,0xff/6);
		}else if (click=='7'){
Timer_CompareVal(Timer_0,0xff/7);
		}else if (click=='8'){
Timer_CompareVal(Timer_0,0xff/8);
		}else if (click=='9'){
Timer_CompareVal(Timer_0,00);
	}
		
	}
}


void led_blink (void){
	if (counter==50){
		LED_toogle(PORT_B,PIN7);
		counter=0;
	}
	counter++;
	Timer_EraseFlag(Timer_0,TOV);
}

void inc (void){
	
	counter= counter+10;
	Timer_CompareVal(Timer_0,0x50-counter);
}

*/



/*
//timer0_fastpwm_interupt
void led_blink (void);
void inc (void);
u8 counter =0;
u8 click=0;
int main (){
	LED_int(PORT_B,PIN7);
	LED_on(PORT_B,PIN7);
	Buzzer_int(PORT_C,PIN6);
	Buzzer_on(PORT_B,PIN7);
	DIO_VoidSetPinDirection(PORT_B,PIN3,OUT);
	Intrupt_GlobalEnable();
	
	
	Timer_mode(Timer_0,fastpwm,clear_oco_oncompare);
	//Timer_InatialVal(Timer_0,0x00);
	Timer_CompareVal(Timer_0,0x50);
	
	BUTTON_init(PORT_D,3,Button_pullup);
	Intrupt_ExternalSense(EInt1,RisingEdge);
	Intrupt_EnableExternal(EInt1);
	EXTI_voidSetCallBack(inc,EInt1);
	
	
//	Timer_intruptEnable(Timer_0,OCIE);
	//TIMER0_callbackfunc(led_blink,Timer_0,OCIE);
	Timer_StartPRESCalerValue(Timer_0,5);
	
	while (1)
	{
		
	}
}


void led_blink (void){
	if (counter==50){
		LED_toogle(PORT_B,PIN7);
		counter=0;
	}
	counter++;
	Timer_EraseFlag(Timer_0,TOV);
}

void inc (void){
	
	counter= counter+10;
Timer_CompareVal(Timer_0,0x50-counter);
}
*/


/*

//timer0_interupt
void led_blink (void);
void inc (void);
u8 counter =0;
u8 click=0;
int main (){
	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	Intrupt_GlobalEnable();
	
	BUTTON_init(PORT_D,3,Button_pullup);
	Intrupt_ExternalSense(EInt1,RisingEdge);
	Intrupt_EnableExternal(EInt1);
	EXTI_voidSetCallBack(inc,EInt1);
	
	Timer_mode(Timer_0,Normal,0);
	Timer_InatialVal(Timer_0,0x00);
	Timer_intruptEnable(Timer_0,TOIE);
	TIMER0_callbackfunc(led_blink,Timer_0,TOIE);
	Timer_StartPRESCalerValue(Timer_0,5);
	while (1)
	{
		
	}
}

void inc (void){
	if(click==0){
	Timer_StartPRESCalerValue(Timer_0,0);
	click=1;
	}else if (click ==1){
		Timer_StartPRESCalerValue(Timer_0,5);
		click=0;
	}
}
void led_blink (void){
	if (counter==50){
	LED_toogle(PORT_B,PIN7);
	counter=0;
	}
	counter++;
	Timer_EraseFlag(Timer_0,TOV);	
}
*/

//timer0_pooling

/*

int main (){
	LED_int(PORT_B,PIN7);
	Timer_mode(Timer_0,Normal,0);
	Timer_InatialVal(Timer_0,0x00);
	Timer_StartPRESCalerValue(Timer_0,3);
	
	u8 flaaaag;
	while (1)
	{
		Timer_ReadFlag(Timer_0,TOV,&flaaaag);
		if (flaaaag==1)
		{
			flaaaag=0;
			LED_toogle(PORT_B,PIN7);
		Timer_EraseFlag(Timer_0,TOV);	
		Timer_InatialVal(Timer_0,0x00);
		Timer_StartPRESCalerValue(Timer_0,3);
		}
		
		
	}
	
}*/

