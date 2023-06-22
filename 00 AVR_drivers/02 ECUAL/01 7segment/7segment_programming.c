#include "7segment_interface.h"

u8  segpins4pov[8];
u8  segpins4pov4pov[5];
void seg_Setconnection(u8 segmport ,u8 PA ,u8 PB,u8 PC,u8 PD,u8 PE,u8 PF,u8 PG)
{
	LED_int(segmport,PA);
	LED_int(segmport,PB);
	LED_int(segmport,PC);
	LED_int(segmport,PD);
	LED_int(segmport,PE);
	LED_int(segmport,PF);
	LED_int(segmport,PG);
	
	LED_int(ENPort1,ENPin1);
	/*LED_int(ENPort2,ENPin2);
	LED_int(ENPort3,ENPin3);
	LED_int(ENPort4,ENPin4);*/
	
	segpins4pov[0]=PA;
	segpins4pov[1]=PB;
	segpins4pov[2]=PC;
	segpins4pov[3]=PD;
	segpins4pov[4]=PE;
	segpins4pov[5]=PF;
	segpins4pov[6]=PG;
	segpins4pov[7]=segmport;

}

void seg_printNum(u8 Num){
#if (seg_type ==  common_anode)
if (Num == 1){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG

}else if(Num ==2 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==3 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); //PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==4 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==5 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==6 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==7 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==8 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==9 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==0 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else{
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}
#endif



#if (seg_type ==  common_cathod)
if (Num == 1){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG

}else if(Num ==2 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==3 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); //PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==4 ){
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==5 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==6 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==7 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==8 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==9 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_on(segpins4pov[7],segpins4pov[6]);	//PG
}else if(Num ==0 ){
	LED_on(segpins4pov[7],segpins4pov[0]);	//PA
	LED_on(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_on(segpins4pov[7],segpins4pov[2]);	//PC
	LED_on(segpins4pov[7],segpins4pov[3]);	//PD
	LED_on(segpins4pov[7],segpins4pov[4]);	//PE
	LED_on(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}else{
	LED_off(segpins4pov[7],segpins4pov[0]);	//PA
	LED_off(segpins4pov[7],segpins4pov[1]); 	//PB
	LED_off(segpins4pov[7],segpins4pov[2]);	//PC
	LED_off(segpins4pov[7],segpins4pov[3]);	//PD
	LED_off(segpins4pov[7],segpins4pov[4]);	//PE
	LED_off(segpins4pov[7],segpins4pov[5]);	//pF
	LED_off(segpins4pov[7],segpins4pov[6]);	//PG
}
#endif
}

void seg_SetDecoderConnection(u8 segmport ,u8 PA ,u8 PB,u8 PC,u8 PD){
	
	LED_int(segmport,PA);
	LED_int(segmport,PB);
	LED_int(segmport,PC);
	LED_int(segmport,PD);
	
	LED_int(ENPort1,ENPin1);
	LED_int(ENPort2,ENPin2);
	LED_int(ENPort3,ENPin3);
	LED_int(ENPort4,ENPin4);
	
	segpins4pov[0]=PA;
	segpins4pov[1]=PB;
	segpins4pov[2]=PC;
	segpins4pov[3]=PD;
	segpins4pov[4]=segmport;
}
void seg_printDecoderNum(u8 Num){
	
	//common cathod
	if (Num == 1){
		LED_on(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); //PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		

		}else if(Num ==2 ){
		LED_off(segpins4pov[4],segpins4pov[0]);	//PA
		LED_on(segpins4pov[4],segpins4pov[1]); 	//PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==3 ){
		LED_on(segpins4pov[4],segpins4pov[0]);	//PA
		LED_on(segpins4pov[4],segpins4pov[1]); //PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==4 ){
		LED_off(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); 	//PB
		LED_on(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==5 ){
		LED_on(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); 	//PB
		LED_on(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==6 ){
		LED_off(segpins4pov[4],segpins4pov[0]);	//PA
		LED_on(segpins4pov[4],segpins4pov[1]); 	//PB
		LED_on(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==7 ){
		LED_on(segpins4pov[4],segpins4pov[0]);	//PA
		LED_on(segpins4pov[4],segpins4pov[1]); 	//PB
		LED_on(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==8 ){
		LED_off(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); //PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_on(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==9 ){
		LED_on(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); //PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_on(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else if(Num ==0 ){
		LED_off(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); //PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
		}else{
		LED_off(segpins4pov[4],segpins4pov[0]);	//PA
		LED_off(segpins4pov[4],segpins4pov[1]); //PB
		LED_off(segpins4pov[4],segpins4pov[2]);	//PC
		LED_off(segpins4pov[4],segpins4pov[3]);	//PD
		
	}
}
void seg_printDecoder4Num(u32 NUMber){
	
	u32 num=NUMber;
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
	//divide the number
	char buffer[count+1];
	do {
		buffer[i] = (NUMber % 10) ;
		i++;
		NUMber /= 10;
	} while (NUMber > 0);
	buffer[i] = '\0';

	// Reverse the string
	/*int j = 0;
	i--;
	while (j < i) {
		char temp = buffer[j];
		buffer[j] = buffer[i];
		buffer[i] = temp;
		j++;
		i--;
	}*/
	
	u16 x=0 ;
	
	if (count==1)
	{
		seg_printDecoderNum(buffer[x]);
		DIO_SETPinValue(ENPort1,ENPin1,LOW);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
	}else if (count==2)
	{
		
		seg_printDecoderNum(buffer[x]);
		DIO_SETPinValue(ENPort1,ENPin1,LOW);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		seg_printDecoderNum(buffer[x+1]);
		DIO_SETPinValue(ENPort1,ENPin1,HIGH);
		DIO_SETPinValue(ENPort2,ENPin2,LOW);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		
	}else if (count==3)
	{
		
		seg_printDecoderNum(buffer[x]);
		DIO_SETPinValue(ENPort1,ENPin1,LOW);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		seg_printDecoderNum(buffer[x+1]);
		DIO_SETPinValue(ENPort1,ENPin1,HIGH);
		DIO_SETPinValue(ENPort2,ENPin2,LOW);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		seg_printDecoderNum(buffer[x+2]);
		DIO_SETPinValue(ENPort1,ENPin1,HIGH);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,LOW);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		
	}else if (count==4)
	{
		
		seg_printDecoderNum(buffer[x]);
		DIO_SETPinValue(ENPort1,ENPin1,LOW);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		seg_printDecoderNum(buffer[x+1]);
		DIO_SETPinValue(ENPort1,ENPin1,HIGH);
		DIO_SETPinValue(ENPort2,ENPin2,LOW);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		seg_printDecoderNum(buffer[x+2]);
		DIO_SETPinValue(ENPort1,ENPin1,HIGH);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,LOW);
		DIO_SETPinValue(ENPort3,ENPin4,HIGH);
		_delay_ms(4);
		seg_printDecoderNum(buffer[x+3]);
		DIO_SETPinValue(ENPort1,ENPin1,HIGH);
		DIO_SETPinValue(ENPort2,ENPin2,HIGH);
		DIO_SETPinValue(ENPort3,ENPin3,HIGH);
		DIO_SETPinValue(ENPort3,ENPin4,LOW);
		_delay_ms(4);
		
	}
	
	
	
	
	
}