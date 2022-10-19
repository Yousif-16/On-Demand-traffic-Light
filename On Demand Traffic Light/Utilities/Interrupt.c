#include "Intetrrupt.h"

#include "../Utilities/standard2.h"


void Init_interrupt (uint8 Interrupt_num)
{
	switch (Interrupt_num)
	{
	case Int0:
		SET_BIT(GICR,6);
		break;
	case Int1:
		SET_BIT(GICR,7);
		break;
	case Int2:
		SET_BIT(GICR,5);
		break;
	}
}

void INT_Choose_Mode (uint8 Interrupt_num,uint8 Interrupt_Mood)
{
	switch (Interrupt_num)
	{
	case Int0:
		switch (Interrupt_Mood)
		{
		case Lowlevel:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case AnyLogicalChange:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case FallingEdge:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case Risingedge:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;

		}
		break;

		case Int1:
			switch (Interrupt_Mood)
			{
			case Lowlevel:
				CLEAR_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
			case AnyLogicalChange:
				SET_BIT(MCUCR,ISC10);
				CLEAR_BIT(MCUCR,ISC11);
				break;
			case FallingEdge:
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			case Risingedge:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;

			}
			break;
			case Int2:
				switch (Interrupt_Mood)
				{
				case FallingEdge:
					CLEAR_BIT(MCUCSR,ISC2);
					break;
				case Risingedge:
					SET_BIT(MCUCSR,ISC2);
					break;

				}

				break;

	}
}

void Set_I_bit (void)
{
	sei();
}







