#include "Timers.h"

#include "../../Utilities/standard2.h"
#include "../../Utilities/Utils.h"
//#include "../../Utilities/registers.h"
#include "../../Utilities/MCU.h"
#include "../Led_Driver/led.h"
/*
#include "standard2.h"
#include "Utils.h"
#include "Mem_Map32.h"
#include "led.h"
*/
#include "avr/interrupt.h"

uint8 flag=0;
void Init_Int0 (uint8 Mood,uint8 Prescaler )
{
	switch (Mood)
	{
	case TIMER0_NORMAL_MODE:
		TCNT0=0x00;
		TCCR0&=(~(1<<3))&(~(1<<6));   // normal mood

		break;
	case TIMER0_PHASECORRECT_MODE:

		break;
	case TIMER0_CTC_MODE:

		break;
	case TIMER0_FASTPWM_MODE:

		break;

	}
}

void Set_Delay (float SEC)
{
	float counter;
	SREG|=(1<<7);
	for (counter=0;counter<(4*SEC);counter++)
	{
		TCNT0=0x09;  //initial value 
		TIMSK|=(1<<0);  //enable  (module interrupt enable)
		TCCR0=(1<<7)|(1<<CS00)|(1<<CS02);

		while ((TIFR&(1<<0))==0);
		TIFR|=(1<<0);
		TCCR0=0;
	}
	cli();

}
void Set_Delay_Timer2 (float SEC)
{
	float counter;
	SREG|=(1<<7);
	for (counter=0;counter<(3.9*SEC);counter++)
	{
		TCNT2=0x09;  //initial value 
		TIMSK|=(1<<6);  //enable (module interrupt enable)
		TCCR2=(1<<7)|(1<<CS20)|(1<<CS22)|(1<<CS21);

		while ((TIFR&(1<<6))==0);
		TIFR|=(1<<6);
		TCCR0=0;
	}
cli();
}

