#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO_Driver/GPIO.h"

#define Error_Led   0
#define Success_Led 1

typedef enum
{
	LED_PORTA,LED_PORTB,LED_PORTC,LED_PORTD
}EN_Led_Ports;

#define Led_Pin0 0
#define Led_Pin1 1
#define Led_Pin2 2
#define Led_Pin3 3
#define Led_Pin4 4
#define Led_Pin5 5
#define Led_Pin6 6
#define Led_Pin7 7

#define LED_HIGH 1
#define LED_LOW  0

#define LED_OUTPUT 1

uint8 Led_Init (uint8 Port_num,uint8 Pin_num);
uint8 Turn_Led_On (uint8 Port_num,uint8 Pin_num);
uint8 Turn_Led_Off (uint8 Port_num,uint8 Pin_num);
uint8 Toggle_Led (uint8 Port_num,uint8 Pin_num);


#endif
