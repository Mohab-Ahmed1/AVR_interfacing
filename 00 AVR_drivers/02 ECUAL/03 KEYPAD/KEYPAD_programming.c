

//include part 
#include "KEYPAD_interface.h"	//   0     1


static void _delay_ms(u32 ticks){
	u32 i;
	for( i = 0; i < (ticks*500) ; i++)
	{
		asm("NOP");
	}
}
u8 keypad_rows [Num_Row][2]={0}; //{port ,pin }
u8 keypad_col [NUM_colum][2]={0};

//initialize function
void KEYPAD_Voidinit(void){
	//rows
	DIO_VoidSetPinDirection(ROW1_Port, Row1_pin, OUT);//row1 out
	DIO_VoidSetPinDirection(ROW2_Port, Row2_pin, OUT);//row 2 out
	DIO_VoidSetPinDirection(ROW3_Port, Row3_pin, OUT);//row 3 out
	DIO_VoidSetPinDirection(ROW4_Port, Row4_pin, OUT);//row 4 out
	//columes
	DIO_VoidSetPinDirection(COL1_Port, COL1_pin,IN); //col 1 IN
	DIO_VoidSetPinDirection(COL2_Port, COL2_pin, IN); //col 2 IN
	DIO_VoidSetPinDirection(COL3_Port, COL3_pin, IN);//col 3 IN
	DIO_VoidSetPinDirection(COL4_Port, COL4_pin, IN);//col 4 IN

	//TURN PULL UP RESISTANCE
	DIO_SETPinValue(COL1_Port, COL1_pin, HIGH);// col 1
	DIO_SETPinValue(COL2_Port, COL2_pin, HIGH);//col 2
	DIO_SETPinValue(COL3_Port, COL3_pin, HIGH);//col 3
	DIO_SETPinValue(COL4_Port, COL4_pin, HIGH);// col 4
//rows
keypad_rows[0][0]=ROW1_Port;
keypad_rows[0][1]=Row1_pin;
keypad_rows[1][0]=ROW2_Port;
keypad_rows[1][1]=Row2_pin;
keypad_rows[2][0]=ROW3_Port;
keypad_rows[2][1]=Row3_pin;
keypad_rows[3][0]=ROW4_Port;
keypad_rows[3][1]=Row4_pin;

//colum
keypad_col[0][0]=COL1_Port;
keypad_col[0][1]=COL1_pin;
keypad_col[1][0]=COL2_Port;
keypad_col[1][1]=COL2_pin;
keypad_col[2][0]=COL3_Port;
keypad_col[2][1]=COL3_pin;
keypad_col[3][0]=COL4_Port;
keypad_col[3][1]=COL4_pin;
}

const u8 keypad[4][4] ={
	{'1','2','3','4'},
	{'5','6','7','8'},
	{'9','/',':','c'},
	{'+','-','*','='},
	};
//read function
void KEYPAD_Getpressedkey(u8 *ptr){
	volatile u8 row = 0 ;
  volatile	 u8 colm=0  ;
   u8 x  = 1     ;
   *ptr ='N' ;
   
	for (row=0 ;row<Num_Row ; row++)
	{
		DIO_SETPinValue(keypad_rows[row][0], keypad_rows[row][1] , LOW) ;
		for (colm=0;colm<NUM_colum;colm++)
		{
			 DIO_GetpinValueread (keypad_col[colm][0] ,keypad_col[colm][1],&x);
		 if (x==0 )
		 {
			 *ptr = keypad[row][colm] ;
			 x=1 ;
			
			
		 }
		}
		_delay_ms(100);
		DIO_SETPinValue(keypad_rows[row][0], keypad_rows[row][1] , HIGH) ;
		
	}
	 
}
