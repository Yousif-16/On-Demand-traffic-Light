#ifndef INTERUPT_H_
#define INTERUPT_H_


#include "registers.h"
#include "Utils.h"
#include "standard2.h"
#include "../ECUAL/Led_driver/led.h"

typedef enum
{
	Int0,Int1,Int2
}En_Intx;

typedef enum
{
	Lowlevel,AnyLogicalChange,FallingEdge,Risingedge
}En_INT0_1moods;

void Init_interrupt (uint8 Interrupt_num);
void INT_Choose_Mode (uint8 Interrupt_num,uint8 Interrupt_Mood);
void Set_I_bit (void);



#endif
