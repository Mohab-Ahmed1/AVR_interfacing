
#include "DIO_interface.h"

//input: port number ,pinnumber,direction
//output: enum error state EN_functionstate_t
//function:intalize the direction of pins
EN_functionstate_t DIO_VoidSetPinDirection(u8 portnumber ,u8 pinnumber,u8 direction){
	switch (portnumber)
	{
	case PORT_A:
		if (direction==IN)
		{
			DDRA &= ~(1<<pinnumber);
		} 
		else if(direction==OUT)
		{
			DDRA |= ( 1<< pinnumber);
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
	case PORT_B:
		if (direction==IN)
		{
			DDRB &= ~(1<<pinnumber);
		}
		else if(direction==OUT)
		{
			DDRB |= ( 1<< pinnumber);
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
	case PORT_C:
		if (direction==IN)
		{
			DDRC &= ~(1<<pinnumber);
		}
		else if(direction==OUT)
		{
			DDRC |= ( 1<< pinnumber);
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
	case PORT_D:
		if (direction==IN)
		{
			DDRD &= ~(1<<pinnumber);
		}
		else if(direction==OUT)
		{
			DDRD |= ( 1<< pinnumber);
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
	}
}
//input: port number ,pinnumber,value
//output: enum error state EN_functionstate_t
//function:write data on dio pin
EN_functionstate_t DIO_SETPinValue(u8 portnumber ,u8 pinnumber,u8 value){
	switch (portnumber)
	{
		case PORT_A:
		if (value==LOW)
		{
			PORTA &= ~(1<<pinnumber);
		}
		else if(value==HIGH)
		{
			PORTA |= ( 1<< pinnumber);	
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
		
		case PORT_B:
		if (value==LOW)
		{
			PORTB &= ~(1<<pinnumber);	
		}
		else if(value==HIGH)
		{
			PORTB |= ( 1<< pinnumber);
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
		
		case PORT_C:
		if (value==LOW)
		{
			PORTC &= ~(1<<pinnumber);
		}
		else if(value==HIGH)
		{
			PORTC |= ( 1<< pinnumber);
		}
		else{
			return Function_Error;
		}
		return Function_ok;
		break;
		
		case PORT_D:
		if (value==LOW)
		{
			PORTD &= ~(1<<pinnumber);
		}
		else if(value==HIGH)
		{
			PORTD |= ( 1<< pinnumber);
		}
		else{
		return Function_Error;
		}
		return Function_ok;
		break;
	}
}
//input: port number ,pinnumber
//output: enum error state EN_functionstate_t
//function:toggle data on dio pin
EN_functionstate_t DIO_tooglePinValue(u8 portnumber ,u8 pinnumber){
	switch (portnumber)
	{
		case PORT_A:
		PORTA ^=(1<<pinnumber);
		return Function_ok;
		break;
		case PORT_B:
		PORTB ^=(1<<pinnumber);
		return Function_ok;
		break;
		case PORT_C:
		PORTC ^=(1<<pinnumber);
		return Function_ok;
		break;
		case PORT_D:
		PORTD ^=(1<<pinnumber);
		return Function_ok;
		break;
		return Function_Error;
	}
}
//input: port number ,pinnumber,address to value
//output: enum error state EN_functionstate_t
//function: read data on dio pin
EN_functionstate_t DIO_GetpinValueread (u8 portnumber ,u8 pinnumber,u8 *value){
	switch (portnumber)
	{
		case PORT_A:
		*value=(PINA &(1<<pinnumber))>>pinnumber;
		return Function_ok;
		break;
		case PORT_B:
		*value=(PINB &(1<<pinnumber))>>pinnumber;
		return Function_ok;
		break;
		case PORT_C:
		*value=(PINC &(1<<pinnumber))>>pinnumber;
		return Function_ok;
		break;
		case PORT_D:
		*value=(PIND &(1<<pinnumber))>>pinnumber;
		return Function_ok;
		break;
		return Function_Error;
	}
}


EN_functionstate_t DIO_SetPortVlue (u8 portnumber,u8 value){
	switch (portnumber)
	{
		case PORT_A:PORTA=value	;	break;
		case PORT_B:PORTB=value	;	break;
		case PORT_C:PORTC=value	;	break;
		case PORT_D:PORTD=value	;	break;
	}
	
}
EN_functionstate_t DIo_SetPortDirection (u8 portnumber ,u8 direction){
		switch (portnumber)
		{
			case PORT_A:
			if (direction ==IN)
			{
				DDRA=0x00;
			}else if (direction ==OUT)
			{
				DDRA=0xff;
			}
				;	break;
			case PORT_B:
			if (direction ==IN)
			{
				DDRB=0x00;
			}else if (direction ==OUT)
			{
				DDRB=0xff;
			}	break;
			case PORT_C:
			if (direction ==IN)
			{
				DDRC=0x00;
			}else if (direction ==OUT)
			{
				DDRC=0xff;
			}	break;
			case PORT_D:
			if (direction ==IN)
			{
				DDRD=0x00;
			}else if (direction ==OUT)
			{
				DDRD=0xff;
			}	break;
		}
}

//test  DIO_functions
//input: void
//output: enum error state EN_Driverstate_t
//function: it calls all the apis of the driver and return the driver state
EN_Driverstate_t DIO_Test(void){
	
	#define port PORT_A
	#define pin 1
	#define direc IN
	volatile u8 val= HIGH;
	if(DIO_VoidSetPinDirection(port,pin,direc )!=Function_ok){
			return Driver_Error;
	}else if (DIO_SETPinValue(port,pin,val)!=Function_ok)
	{
			return Driver_Error;
	}else if (DIO_tooglePinValue(port,pin)!=Function_ok){
			return Driver_Error;
	}else if (DIO_GetpinValueread(port,pin,&val)!=Function_ok)
	{
			return Driver_Error;
	}else{
			return Driver_ok;
	}
}
