/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        25 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         HAL
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"


#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


/*First Edge*/
static u8 Global_u8StartEdgeFlag = 0;

/*Time between every two falling edges*/
static u32 Global_u32ReceivedFrame[50] = {0};

/*Carry Decimal Number*/
static u8 Global_u8ButtonData = 0;

/*Edge Number*/
static u8 Global_u8EdgeCounter = 0;


void hIR_voidInit(void)
{
	/*RCC Init*/
	mRCC_voidInit();
	mRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);

	/*Configure PA0*/
	mGPIO_voidSetPinMode(GPIO_A,PIN0,INPUT);
	mGPIO_voidSetConnectionType(GPIO_A,PIN0,PULL_UP);



	/*Configure PA1*/
	mGPIO_voidSetPinMode(GPIO_A,PIN1,OUTPUT);
	/*Configure PA2*/
	mGPIO_voidSetPinMode(GPIO_A,PIN2,OUTPUT);
	/*Configure PA3*/
	mGPIO_voidSetPinMode (GPIO_A,PIN3,OUTPUT);


	/*Init STK*/
	/*On But not counting cuz load = 0 */
	mSYSTICK_voidInit();


	/*EXTI Init*/
	mEXTI_voidInit();
	/*Falling*/
	mEXTI_voidChangeSenseMode(EXTI_LINE0 , EXTI_FALING_EDGE);

	/*Pass The Function*/
	mEXTI_voidSetCallBack(EXTI_LINE0 , &hIR_voidGetFrame);

	/*Enable Interrupt*/
	mEXTI_voidEnableINT(EXTI_LINE0);

	/*NVIC Init*/
	mNVIC_voidInit();

	/*Enable EXT0 Interrupt*/
	mNVIC_voidEnablePeripheralINT(6);

}

void hIR_voidGetFrame(void)
{
	if(Global_u8StartEdgeFlag == 0)
	{
		/*Set timer with Total FrameTime*/
		MSTK_voidSetSingleInterval(60000,&hIR_voidTakeAction);

		Global_u8StartEdgeFlag = 1;
	}
	else
	{	/*Get the counted TIME*/
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = mSYSTICK_u32GetElapsedTime();
		/*Reset Timer*/
		mSYSTICK_voidResetSysTick();

		/*Set PreLoad Value*/
		MSTK_voidSetSingleInterval(60000,&hIR_voidTakeAction);
		/*Inc Edge Counter*/
		Global_u8EdgeCounter++;


	}
}

void hIR_voidTakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8 ; Local_u8LoopCounter ++)
	{
		/*Data From 17 to 24*/
		if ((Global_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&(Global_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			/*Zero*/
			CLR_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}

		else
		{	/*One*/
			SET_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}
	}
	/*Prepare new frame*/
	Global_u8StartEdgeFlag = 0;
	Global_u8EdgeCounter = 0;
}

void hIR_voidPlay(void)
{
	switch(Global_u8ButtonData)
	{

	  case 22://0
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,LOW);
	  	break;
	  case 12://1
	    mGPIO_voidSetPinValue(GPIO_A,PIN1,LOW);
	    mGPIO_voidSetPinValue(GPIO_A,PIN2,HIGH);
	    mGPIO_voidSetPinValue(GPIO_A,PIN3,LOW);
	  	break;
	  case 24://2
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,HIGH);
	  	break;
	  case 94://3
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,LOW);
	  	break;
	  case 8://4
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,HIGH);
	  	break;
	  case 28://5
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,HIGH);
	  	break;
	  case 90://6
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,HIGH);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,HIGH);
	  	break;
	  case 69://ON-OFF
	  	mGPIO_voidSetPinValue(GPIO_A,PIN1,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN2,LOW);
	  	mGPIO_voidSetPinValue(GPIO_A,PIN3,LOW);
	  	break;
	}
}
