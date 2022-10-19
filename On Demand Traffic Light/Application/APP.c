
#include "app.h"
#include <avr/delay.h>

uint8 flag_red=0;
uint8 flag_green=0;
uint8 flag_yellow=0;
uint8 counter=0;
uint8 flag_main=0;
ISR(INT0_vect)
{
	if (flag_red==1)
	{
		Turn_Led_On(LED_PORTB,0);
		Turn_Led_Off(LED_PORTB, Led_Pin1);
		Turn_Led_Off(LED_PORTB, Led_Pin2);
		Set_Delay(84);
		Turn_Led_Off(LED_PORTB, Led_Pin0);
		Turn_Led_Off(LED_PORTA, Led_Pin2);


	}
	else if (flag_yellow==1||flag_green==1)
	{
		/***********************************/ 
		Turn_Led_On(LED_PORTB, Led_Pin2);
		Turn_Led_Off(LED_PORTB, Led_Pin0);
		/***********************************/
		/***********************************/ 
		Turn_Led_On(LED_PORTB,2);
		Turn_Led_Off(LED_PORTA, Led_Pin0);
		Turn_Led_Off(LED_PORTA, Led_Pin2);
		Turn_Led_Off(LED_PORTA, Led_Pin1);

		/***********************************/
		for(counter=10;counter>1;counter--)
		{
			Toggle_Led(LED_PORTA,Led_Pin1);
			Toggle_Led(LED_PORTB,Led_Pin1);
		
			Set_Delay(25);
		}
		
		Turn_Led_Off(LED_PORTB, Led_Pin1);
		Turn_Led_Off(LED_PORTB, Led_Pin2);
		Turn_Led_Off(LED_PORTA, Led_Pin1);

		Turn_Led_On(LED_PORTB,0);
		Turn_Led_On(LED_PORTA,2);


		Set_Delay(84);

		Turn_Led_Off(LED_PORTB,0);


	}
	flag_red=0;
	flag_yellow=0;
	flag_green=0;
sei();
}

void app_start()
{
	
	Led_Init(LED_PORTA,Led_Pin0);
	Led_Init(LED_PORTA,Led_Pin1);
	Led_Init(LED_PORTA,Led_Pin2);
	Led_Init(LED_PORTB,Led_Pin0);
	Led_Init(LED_PORTB,Led_Pin1);
	Led_Init(LED_PORTB,Led_Pin2);

	Turn_Led_Off(LED_PORTA, Led_Pin0);
	Turn_Led_Off(LED_PORTA, Led_Pin1);
	Turn_Led_Off(LED_PORTA, Led_Pin2);
	Turn_Led_Off(LED_PORTB, Led_Pin0);
	Turn_Led_Off(LED_PORTB, Led_Pin1);
	Turn_Led_Off(LED_PORTB, Led_Pin2);
	/*******************************************/
	Init_Button(Button_PORTD,2);
	/*******************************************/
	//Init_Int0 (TIMER0_NORMAL_MODE, TIMER0_PreSCALER_1 );
	Init_interrupt(Int0);
	SREG|=(1<<7);
	MCUCR|=(1<<0)|(1<<1);
	/*******************************************/
	
	while (1)
	{

		Turn_Led_On(LED_PORTA, Led_Pin0); // car_green
		flag_green=1;
		
		Set_Delay_Timer2(5);

		Turn_Led_Off(LED_PORTA, Led_Pin0);
		flag_green=0;

		Turn_Led_On(LED_PORTA, Led_Pin1); // car_yellow
		flag_yellow=1;
		
		Set_Delay_Timer2(84);

		Turn_Led_Off(LED_PORTA, Led_Pin1);
		flag_yellow=0;

		Turn_Led_On(LED_PORTA, Led_Pin2); // car_red
		flag_red=1;
		
		Set_Delay_Timer2(84);

		Turn_Led_Off(LED_PORTA, Led_Pin2);
		flag_red=0;

	}





}
	


