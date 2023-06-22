
#ifndef BUTTON_Interface_H_
#define BUTTON_Interface_H_

#include  "button_config.h"
#include "../../01 MCAL/00 DIO driver/DIO_interface.h"


//pullup_or_pulldown
typedef enum{
	Button_NOpull,
	Button_pullup,
	Button_Pulldown
}button_state;

//button intalize
//input:buttonport and button pin
//output:void
//function: this will make the button port to an input
void BUTTON_init(u8 buttonport ,u8 buttonpin,button_state state);
//button read
//input:buttonport and button pin
//output:void
//function:this will read the current reading of the required port and pin
void BUTTON_read(u8 buttonport,u8 buttonpin ,u8 *value);//button read



#endif /* BUTTON_Interface_H_ */
