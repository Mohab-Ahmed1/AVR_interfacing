#ifndef		BIT_MATH_H
#define		BIT_MATH_H

#define		SET_BIT(REG,BIT)		(REG|=  (1<<BIT))
#define		CLR_BIT(REG,BIT)		(REG&= ~(1<<BIT))
#define		TOG_BIT(REG,BIT)		(REG^=  (1<<BIT))
#define		GET_BIT(REG,BIT)		((REG>>BIT)&0x01)

#define CONC_BIT(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0) CONC_HELP(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0)
#define CONC_HELP(bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0) 0b##bit7##bit6##bit5##bit4##bit3##bit2##bit1##bit0
//#define		BIT_LOW					((u8)0)

#endif