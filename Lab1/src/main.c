/* This program to test GPIO Driver */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


int main(void)
{

	mRCC_voidInit();
	mRCC_voidEnablePeripheralClock(RCC_AHB1,GPIO_A);
	mGPIO_voidSetPinMode(GPIO_A,PIN0,1);


	while(1)
	{
		mGPIO_voidSetPinValue(GPIO_A,PIN0,HIGH);


		mGPIO_voidSetPinValue(GPIO_A,PIN0,LOW);




	}




}
