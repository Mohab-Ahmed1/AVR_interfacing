#ifndef		STD_TYPES_H
#define		STD_TYPES_H
//test enum
typedef enum EN_functionstate_t{
	Function_ok,
	Function_Error
}EN_functionstate_t;

typedef enum EN_Driverstate_t{
	Driver_ok,
	Driver_Error
}EN_Driverstate_t;



typedef		unsigned	char			u8;
typedef		unsigned	short	int		u16;
typedef		unsigned			int		u32;
typedef		unsigned	long	int		u64;

typedef							float	f32;
typedef							double	f64;

typedef		signed		char			s8;
typedef		signed		short	int		s16;
typedef		signed				int		s32;
typedef		signed		long	int		s64;

#ifndef		NULL
#define		NULL			((void *)0)
#endif


#endif
