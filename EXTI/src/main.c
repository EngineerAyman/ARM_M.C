#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
void Toggle_LED(void);

void main (void)
{

	mRCC_voidInit();
	mRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);


	mGPIO_voidSetPinMode(GPIO_A,PIN0,INPUT);
	mGPIO_voidSetPinValue(GPIO_A,PIN0,PULL_UP);


	mGPIO_voidSetPinMode(GPIO_A,PIN0,OUTPUT);
	mGPIO_voidSetPinValue(GPIO_A,PIN0,HIGH);


	mNVIC_voidInit();
	mNVIC_voidEnablePeripheralINT(6);

	mEXTI_voidChangeSenseMode(0,EXTI_FALING_EDGE);//
	mEXTI_voidSetCallBack(0,&Toggle_LED);
	mEXTI_voidEnableINT(0);


	while(1)
		;

	}

void Toggle_LED(void)
{
	asm ("NOP");
}
