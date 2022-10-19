#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO_Driver/GPIO.h"

#define Success_Button 0
#define Error_Button   1

typedef enum
{
	Button_PORTA,Button_PORTB,Button_PORTC,Button_PORTD
}En_Button_Ports;

uint8 Init_Button (uint8 Port_num,uint8 Pin_num);





#endif
