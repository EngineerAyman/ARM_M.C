#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"
void APP_GETFRAME(void);
u8 APP_u8StartEdgeFlag = 0;
void main (void)
{

	mRCC_voidInit();
	mRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);

	// FOR EXTERNAL INT AND RISING EDGE
	mGPIO_voidSetPinMode(GPIO_A,PIN0,INPUT);
	mGPIO_voidSetPinValue(GPIO_A,PIN0,PULL_UP);
    // init SYSTICK
    mSYSTICK_voidInit();


    // TO SET GROUP AND SUB YON NOT USE IT

	mEXTI_voidInit();
	mEXTI_voidChangeSenseMode(0,EXTI_FALING_EDGE);//
    mEXTI_voidSetCallBack(0,&APP_GETFRAME);
	mEXTI_voidEnableINT(0);

	mNVIC_voidInit();
	mNVIC_voidEnablePeripheralINT(6);




	while(1);


	}

void APP_GETFRAME(void)
{
	if (APP_u8StartEdgeFlag == 0)
	{
		//Ms
	}

}
