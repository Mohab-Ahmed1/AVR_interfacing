#ifndef		LCD_config_H
#define		LCD_config_H

//model  of lcd
enum{
	fourX20,
	twox16
	};

//connection mode
enum{
	four_bitmode,
	Eight_bitmode
	};
	
#define D4_data_port	PORT_B
#define  D4				PIN0
#define D5_data_port	PORT_B
#define  D5				PIN1
#define D6_data_port	PORT_B
#define  D6				PIN2
#define D7_data_port	PORT_B
#define  D7				PIN4

#define RW_control_port		PORT_A
#define  RW					'N'  //put  N if not using and hardware connected 
#define EN_control_port		PORT_A
#define  EN					PIN2   
#define RS_control_port		PORT_A
#define  RS					PIN3






#define connection_mode  four_bitmode
#endif
