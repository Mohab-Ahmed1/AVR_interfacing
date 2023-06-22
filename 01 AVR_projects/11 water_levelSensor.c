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


//ADC interupt
void read (void);
u8 x =0;
u32 number ;
ADCMODE_t ADCTO_READ = ADC_0 ;
u8 scadular =0 ;
u32 reading [5];
int main (){

	LED_int(PORT_B,PIN7);
	LED_off(PORT_B,PIN7);
	DIO_VoidSetPinDirection(PORT_A,PIN0,IN);
	DIO_VoidSetPinDirection(PORT_A,PIN1,IN);
	DIO_VoidSetPinDirection(PORT_A,PIN4,IN);
	DIO_VoidSetPinDirection(PORT_A,PIN7,IN);
	seg_SetDecoderConnection(PORT_B,PIN0,PIN1,PIN2,PIN4);
	
	ADC_voidSetCallBack(read);
	Intrupt_GlobalEnable();
	ADC_Intalize();
	ADC_SETADCMux_Mode(ADCTO_READ);
	ADC_startconversion();
	while (1)
	{
		ADC_startconversion();
		ADC_SETADCMux_Mode(ADCTO_READ);
		//seg_printDecoder4Num(reading[scadular]);
		if(x==1){
				ADC_GETDATAvalue(&number);
				x=0;
				if (scadular==0)
				{	ADCTO_READ=ADC_1;
					
					if (number>=100)
					{
						reading[0]=1;
					}else{
						reading[0]=0;
					}
					
					scadular=1;
					
				}
				 else if (scadular==1)
				{	ADCTO_READ=ADC_4;
					
					if (number>=100)
					{
						reading[1]=1;
						}else{
						reading[1]=0;
					}	
					scadular=2;
					
				}
				else if (scadular==2){
					ADCTO_READ=ADC_7;
					
					if (number>=100)
					{
						reading[2]=1;
						}else{
						reading[2]=0;
					}
					scadular=3;
				}
				else if (scadular==3){
					ADCTO_READ=ADC_0;
				
					if (number>=100)
					{	reading[3]=1;
						}else{
						reading[3]=0;
					}
					scadular=0;
				}
			}
		
//########################################	
seg_printDecoder4Num(reading[0]+reading[1]+reading[2]+reading[3]);
/*

	if(reading[0]+reading[1]+reading[2]+reading[3]==1){
		seg_printDecoder4Num(1);
		}
		if(reading[0]+reading[1]+reading[2]+reading[3]==2){
		seg_printDecoder4Num(2);
		}
		if(reading[0]+reading[1]+reading[2]+reading[3]==3){
		seg_printDecoder4Num(3);
		}
		if (reading[0]+reading[1]+reading[2]+reading[3]==4)
		{
			seg_printDecoder4Num(4);		
		}
		if(reading[0]+reading[1]+reading[2]+reading[3]==0){
		seg_printDecoder4Num(0);
		}
		*/	
		
		ADC_EnableInterupt();
	}
	
}
void read (void){
	x=1;
	
	ADC_DisableInterupt ();
}