#ifndef		segment_interface_H
#define		segment_interface_H

#include "7segment_config.h"
#include "../00 LED/LED_interfce.h"
#define F_CPU 16000000Ul
#include <util/delay.h>



void seg_Setconnection(u8 segmport ,u8 PA ,u8 PB,u8 PC,u8 PD,u8 PE ,u8 PF,u8 PG);

void seg_printNum(u8 Num);

void seg_SetDecoderConnection(u8 segmport ,u8 PA ,u8 PB,u8 PC,u8 PD);
void seg_printDecoderNum(u8 Num);
void seg_printDecoder4Num(u32 NUMber);





/*
DIO_VoidSetPinDirection(PORT_A,4,OUT);
DIO_SETPinValue(PORT_A,4,HIGH);

seg_SetDecoderConnection(PORT_B ,0 ,1,2,4);

DIO_VoidSetPinDirection(PORT_A,3,OUT);
DIO_VoidSetPinDirection(PORT_A,2,OUT);
DIO_VoidSetPinDirection(PORT_B,5,OUT);
DIO_VoidSetPinDirection(PORT_B,6,OUT);
seg_printDecoder4Num(1234);
*/












#endif
