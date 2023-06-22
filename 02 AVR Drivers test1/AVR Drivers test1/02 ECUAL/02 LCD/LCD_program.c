#include "lCD_interface.h"
/*
#define F_CPU  16000000ul
#include <util/delay.h>*/
static void _delay_us(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*50) ; i++)
	{
		asm("NOP");
	}
}

static void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}
//intalize the bits
void LCD_4_bit_intalize(void){
//data bins intalize 
{
	DIO_VoidSetPinDirection(D4_data_port, D4, OUT);
	DIO_VoidSetPinDirection(D5_data_port, D5, OUT);
	DIO_VoidSetPinDirection(D6_data_port, D6, OUT);
	DIO_VoidSetPinDirection(D7_data_port, D7, OUT);
}

//control pins intalized
{
#if RW !='N'
DIO_VoidSetPinDirection(RW_control_port, RW, OUT);
#endif

DIO_VoidSetPinDirection(EN_control_port, EN, OUT);
DIO_VoidSetPinDirection(RS_control_port, RS, OUT);
_delay_ms(50);
}
// setup lcd 
{
	
	LCD_4_bit_sendcommand(0x33); // Ensures display is in 8-bit mode
	
	LCD_4_bit_sendcommand(0x32);  // Puts display in 4-bit mode
	LCD_4_bit_sendcommand(TWOline_4bitmode);
	_delay_ms(10) ;
	LCD_4_bit_sendcommand(cursor_blink);
	_delay_ms(10) ;
	LCD_4_bit_sendcommand(clear_display);
	_delay_ms(10) ;
	_delay_ms(10) ;

LCD_4_bit_sendcommand(cursor_leftToright);
	//LCD_4_bit_sendcommand(0x07);
	_delay_ms(1000) ;
	
}

}


void LCD_4_bit_sendcommand(u8 cmnd){
DIO_SETPinValue(RS_control_port,RS , LOW) ;
#if RW !='N'
DIO_SETPinValue(RW_control_port,RW , LOW) ;
#endif
//higher niple send
{


DIO_SETPinValue(D4_data_port,D4 , GET_BIT(cmnd,4)) ;
DIO_SETPinValue(D5_data_port,D5 , GET_BIT(cmnd,5));
DIO_SETPinValue(D6_data_port,D6 , GET_BIT(cmnd,6)) ;
DIO_SETPinValue(D7_data_port,D7 , GET_BIT(cmnd,7));


DIO_SETPinValue(EN_control_port,EN,HIGH);//enable  pulse =1
_delay_us(10);
DIO_SETPinValue(EN_control_port,EN,LOW); //enable pulse =0
_delay_us(10);
}
//lower niple send
{
	

DIO_SETPinValue(D4_data_port,D4 , GET_BIT(cmnd,0)) ;
DIO_SETPinValue(D5_data_port,D5 , GET_BIT(cmnd,1));
DIO_SETPinValue(D6_data_port,D6 , GET_BIT(cmnd,2)) ;
DIO_SETPinValue(D7_data_port,D7 , GET_BIT(cmnd,3));

DIO_SETPinValue(EN_control_port,EN,HIGH);//enable  pulse =1
_delay_us(10);
DIO_SETPinValue(EN_control_port,EN,LOW); //enable pulse =0
_delay_us(10);
}

}

void LCD_4_bit_sendchar(u8 cmnd){
	DIO_SETPinValue(RS_control_port,RS , HIGH) ;
	#if RW !='N'
	DIO_SETPinValue(RW_control_port,RW , LOW) ;
    #endif

	
	DIO_SETPinValue(D4_data_port,D4 , GET_BIT(cmnd,4)) ;
	DIO_SETPinValue(D5_data_port,D5 , GET_BIT(cmnd,5));
	DIO_SETPinValue(D6_data_port,D6 , GET_BIT(cmnd,6)) ;
	DIO_SETPinValue(D7_data_port,D7 , GET_BIT(cmnd,7));
	
	
	DIO_SETPinValue(EN_control_port,EN,HIGH);//enable  pulse =1
	_delay_us(10);
	DIO_SETPinValue(EN_control_port,EN,LOW); //enable pulse =0
	_delay_us(10);


//	GPIOB_ODR=(GPIOB_ODR&0x0fff) |(comnd_16bit <<4);
DIO_SETPinValue(D4_data_port,D4 , GET_BIT(cmnd,0)) ;
DIO_SETPinValue(D5_data_port,D5 , GET_BIT(cmnd,1));
DIO_SETPinValue(D6_data_port,D6 , GET_BIT(cmnd,2)) ;
DIO_SETPinValue(D7_data_port,D7 , GET_BIT(cmnd,3));

	DIO_SETPinValue(EN_control_port,EN,HIGH);//enable  pulse =1
	_delay_us(10);
	DIO_SETPinValue(EN_control_port,EN,LOW); //enable pulse =0
	_delay_us(10);

}

void Lcd_4_bit_sendstring(u8 *str){

	while(*str != '\0')
		{
		LCD_4_bit_sendchar(*str) ;
			str++ ;
		}

}
void Lcd_4_bit_sendnumber(u32 number){

	
u32 num=number;
u16 count=0;

int i=0;

// count the no of degits
  if (num == 0) {
	  count = 1;
	  } else {
	  while (num != 0) {
		  num /= 10;
		  count++;
	  }
  }
  
  char buffer[count+1];
// Convert the number to a string manually


if (number < 0) {
	buffer[i] = 'A';
	i++;
	number = -number;
}
do {
	buffer[i] = (number % 10) + '0';
	i++;
	number /= 10;
} while (number > 0);
buffer[i] = '\0';

// Reverse the string
int j = 0;
i--;
while (j < i) {
	char temp = buffer[j];
	buffer[j] = buffer[i];
	buffer[i] = temp;
	j++;
	i--;
}

for (u16 x=0 ;x<count;x++)
{
	LCD_4_bit_sendchar(buffer[x]);
}

}

void Lcd_4_bit_courserposition(u8 Row ,u8 column ){

	if (Row<5 &&column<17)
		{
			switch(Row){
				case 1 : LCD_4_bit_sendcommand(0X80+column) ;//0x80+0x00
				break;
				case 2: LCD_4_bit_sendcommand(0XC0+column)  ;//0x80+0x40
				break;
				case 3: LCD_4_bit_sendcommand(0X94+column)  ;//0x80+0x14
				break;
				case 4: LCD_4_bit_sendcommand(0XD4+column)  ;//0x80+0x54
				break;
			}
			}else {

		}
}



//fix the create custom
void Lcd_4_bit_createcustomchar(u8 *pattern ,u8 location){ //it is defined befour the lcd_initalize
	u8 i=0;
	u8 counter=0;

	LCD_4_bit_sendcommand(0x40+(location*8));  //send the address of CGram

	for(i=0;i<8 ;i++){
		LCD_4_bit_sendchar(pattern[i]); //pass the pattern to the lcd
	}


}

void Lcd_4_bit_printCustomChar(u8 location){
	LCD_4_bit_sendchar(location);
}

