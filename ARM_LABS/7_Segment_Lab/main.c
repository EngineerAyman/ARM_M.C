#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
int main(void)
{
	u32 Local_u32LoopCounter=0;
	u32 arr[]={
				0x3F,   /* 0 */
				0x06,   /* 1 */
				0x5B,   /* 2 */
				0x4F,   /* 3 */
				0x66,   /* 4 */
				0x6D,   /* 5 */
				0x7D,   /* 6 */
				0x07,   /* 7 */
				0x7F,   /* 8 */
				0x6F    /* 9 */};

	// Init RCC
	mRCC_voidInit();
	// GPIO Enable
	mRCC_voidEnablePeripheralClock(RCC_AHB1,GPIO_A);
	// SYSTICK Init
	mSYSTICK_voidInit();
	// Set PORT mode
	mGPIO_voidSetPortSpecificMode(GPIO_A,1);
	mGPIO_voidSetPortSpecificMode(GPIO_B,1);

//	// Pin Speed
//	mGPIO_voidSetOutputSpeed(GPIO_A,PIN0,1);
//	// pin Output type
//	mGPIO_voidSetOutputType(GPIO_A,PIN0,1);


	while(1)
	{

		for (Local_u32LoopCounter=0;Local_u32LoopCounter<10;Local_u32LoopCounter++)
		{
			// Set PORT Value
			mGPIO_voidSetPortSpecificValue(GPIO_A,arr[Local_u32LoopCounter]);
			mSYSTICK_voidBusyWait(1000000);
		}
		for (Local_u32LoopCounter=10;Local_u32LoopCounter<0;Local_u32LoopCounter--)
				{
					// Set PORT Value
					mGPIO_voidSetPortSpecificValue(GPIO_B,arr[Local_u32LoopCounter]);
					mSYSTICK_voidBusyWait(1000000);
				}
	}




}
