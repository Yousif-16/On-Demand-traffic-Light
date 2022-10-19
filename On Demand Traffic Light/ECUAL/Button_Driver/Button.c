#include "Button.h"


uint8 Init_Button (uint8 Port_num,uint8 Pin_num)
{
	uint8 ret_val=Success_Button;
	if(Port_num>3||Pin_num>7)
	{
		ret_val=Error_Button;
	}
	else
	{
		GPIO_InitPin(Port_num, Pin_num,INPUT);
	}
	return ret_val;
}
