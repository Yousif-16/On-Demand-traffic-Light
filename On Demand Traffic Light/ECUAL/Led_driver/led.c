#include "led.h"
uint8 Led_Init (uint8 Port_num,uint8 Pin_num)
{
	uint8 ret_value =Success_Led ;
		if (Pin_num>7||Port_num>3)
		{
			return Error_Led;
		}
		else
		{
			GPIO_InitPin(Port_num,Pin_num,LED_OUTPUT);
		}
		return ret_value;
}

uint8 Turn_Led_On (uint8 Port_num,uint8 Pin_num)
{
	uint8 ret_value =Success_Led ;
	if (Pin_num>7||Port_num>3)
	{
		return Error_Led;
	}
	else
	{
		switch (Port_num)
		{
		case LED_PORTA:
			GPIO_WritePin(LED_PORTA,Pin_num,LED_HIGH);
			break;
		case LED_PORTB:
			GPIO_WritePin(LED_PORTB,Pin_num,LED_HIGH);
			break;
		case LED_PORTC:
			GPIO_WritePin(LED_PORTC,Pin_num,LED_HIGH);
			break;
		case LED_PORTD:
			GPIO_WritePin(LED_PORTD,Pin_num,LED_HIGH);
			break;

		}
	}
	return ret_value;

}


uint8 Turn_Led_Off (uint8 Port_num,uint8 Pin_num)
{
	uint8 ret_value =Success_Led ;
	if (Pin_num>7||Port_num>3)
	{
		return Error_Led;
	}
	else
	{
		switch (Port_num)
		{
		case LED_PORTA:
			GPIO_WritePin(LED_PORTA,Pin_num,LED_LOW);
			break;
		case LED_PORTB:
			GPIO_WritePin(LED_PORTB,Pin_num,LED_LOW);
			break;
		case LED_PORTC:
			GPIO_WritePin(LED_PORTC,Pin_num,LED_LOW);
			break;
		case LED_PORTD:
			GPIO_WritePin(LED_PORTD,Pin_num,LED_LOW);
			break;

		}
	}
	return ret_value;

}

uint8 Toggle_Led (uint8 Port_num,uint8 Pin_num)
{
	uint8 ret_val;
	if(Port_num>3||Pin_num>7)
	{
		ret_val=Error_Led;
	}
	else
	{
		GPIO_TogglePin(Port_num,Pin_num);
	}
	return ret_val;
}





