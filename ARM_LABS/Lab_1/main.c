/* This program to test GPIO Driver */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"



void main (void)
{

    // Init RCC
	MRCC_voidInit();
	// SYSTICK Init
	Systick_voidInitiate();
	// ENABLE RCC
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	// PIN MODE
	MGPIO_voidSetPinMode( MGPIO_PORTA ,PIN0,1);

	// Pin Output
	MGPIO_voidSetPinOutputType(MGPIO_PORTA , PIN0, 1);

	// Pin Speed
	MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA , PIN0, 1);


	while(1)
		{

		MGPIO_voidSetPinValue(MGPIO_PORTA ,  PIN0, HIGH);
		Systick_voidBusyWait(1000000);
		MGPIO_voidSetPinValue(MGPIO_PORTA ,  PIN0, HIGH);
		Systick_voidBusyWait(1000000);

		}





}
