

#ifndef KEYPAD_H_
#define KEYPAD_H_
//include part

#include "../../01 MCAL/00 DIO driver/DIO_interface.h"
#include "KEYPAD_config.h"

//initialize function  
void KEYPAD_Voidinit(void );
//read function  
void KEYPAD_Getpressedkey(u8 *ptr);




#endif /* KEYPAD_H_ */
