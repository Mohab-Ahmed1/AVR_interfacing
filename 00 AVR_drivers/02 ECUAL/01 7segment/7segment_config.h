#ifndef		segment_config_H
#define		segment_config_H

typedef enum{
	common_anode,
	common_cathod

}seg;



#define   seg_type   common_cathod

#define ENPort1		PORT_A//7seg1
#define ENPin1		3
#define ENPort2		PORT_A//7seg2
#define ENPin2		2
#define ENPort3		PORT_B//7seg3
#define ENPin3		5
#define ENPort4		PORT_B//7seg4
#define ENPin4		6


#endif
