
//button intalize

#include "button_Interface.h"


//button intalize
//input:buttonport and button pin
//output:void
//function: this will make the button port to an input
void BUTTON_init(u8 buttonport ,u8 buttonpin,button_state state){
	DIO_VoidSetPinDirection(buttonport,buttonpin,IN);
	
	switch (state){
	case Button_pullup :  DIO_SETPinValue(buttonport, buttonpin, HIGH);  break;
	//case Button_Pulldown:   DIO_voidSetPinValue(buttonport, buttonpin, GPIO_LOW);  break;
	case Button_NOpull: break;
	}
}
//button read
//input:buttonport and button pin
//output:void
//function:this will read the current reading of the required port and pin
void BUTTON_read(u8 buttonport,u8 buttonpin ,u8 *value){
	 DIO_GetpinValueread(buttonport,buttonpin,value);
	 
}
