#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

int main(void)
{
	// Init RCC
	mRCC_voidInit();
	// SYSTICK Init
	mSYSTICK_voidInit();
	// GPIO Enable
	mRCC_voidEnablePeripheralClock(RCC_AHB1,GPIO_A);
	// Set Pin mode
	mGPIO_voidSetPinMode(GPIO_A,PIN0,1);
	// Pin Speed
	mGPIO_voidSetOutputSpeed(GPIO_A,PIN0,1);
	// pin Output type
	mGPIO_voidSetOutputType(GPIO_A,PIN0,1);


	while(1)
	{
		mGPIO_voidSetPinValue(GPIO_A,PIN0,HIGH);
		// Delay for 1 sec
        mSYSTICK_voidBusyWait(1000000);
		mGPIO_voidSetPinValue(GPIO_A,PIN0,LOW);
		mSYSTICK_voidBusyWait(1000000);
	}




}
