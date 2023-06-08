#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "TFT_interface.h"
#include "Image.h"

void main(void)
{
	mRCC_voidInit();
	mRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	mRCC_voidEnablePeripheralClock(RCC_APB2,12);
	mSYSTICK_voidInit();
	MSPI1_voidInit();
	HTFT_voidInit();


	while(1)
	{
		HTFT_voidDisplayImage(&Image_arr);
	}
}
