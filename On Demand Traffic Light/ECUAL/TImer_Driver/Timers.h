#ifndef  TIMERS_H_
#define  TIMERS_H_
#include "../../Utilities/standard2.h"

typedef enum{
	TIMER0_STOP=0,
	TIMER0_PreSCALER_1,
	TIMER0_PreSCALER_8,
	TIMER0_PreSCALER_64,
	TIMER0_PreSCALER_256,
	TIMER0_PreSCALER_1024,
	EXTERNALl_FALLING_Edge,
	EXTERNAL_RISING_Edge
}TIMER0_Prescalar;

typedef enum
{
	TIMER0_NORMAL_MODE,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
}TIMER0_Mode_t;

void Init_Int0 (uint8 Mood,uint8 Prescaler );
void Set_Delay (float SEC);
void Set_Delay_Timer2 (float SEC);




#endif
