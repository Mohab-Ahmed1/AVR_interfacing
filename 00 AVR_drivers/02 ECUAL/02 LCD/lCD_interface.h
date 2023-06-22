#ifndef		LCD_Interface_H
#define		LCD_Interface_H


#include "../../01 MCAL/00 DIO driver/DIO_interface.h"
#include "LCD_config.h"

/*
//temp
#define F_CPU 16000000Ul
#include <util/delay.h>
*/

//commands to lcd
#define clear_display			0x01
#define cursor_leftToright		0x06
#define cursor_NOSHift			0x05//0x07
#define cursor_off				0x0c
#define cursor_blink			0x0E
#define cursor_firstline		0x80
#define cursor_secandline		0xc0
//
#define cursor_shiftleft		0x10
#define cursor_shiftright		0x14
#define display_shiftleft		0x18
#define display_shiftright		0x1c
//
#define TWOline_8bitmode		0x38
#define TWOline_4bitmode		0x28
#define ONEline_8bitmode		0x30
#define ONEline_4bitmode		0x20


//void LCD_intalize(void);
void LCD_4_bit_intalize(void);
void LCD_4_bit_sendcommand(u8 cmnd);
void LCD_4_bit_sendchar(u8 cmnd);
void Lcd_4_bit_sendstring(u8 *str);
void Lcd_4_bit_courserposition(u8 Row ,u8 column );
void Lcd_4_bit_sendnumber(u32 num);
void Lcd_4_bit_createcustomchar(u8 *pattern ,u8 location);//it is defined befour the lcd_initalize
void Lcd_4_bit_printCustomChar(u8 location);




#endif
