/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        9 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

// static void (*pvCallBackFunction)(void) = NULL;
// static u8 u8IntervalFlag = SINGLE_INTERVAL;

void mSYSTICK_voidInit(void)
{
/* Choose The Clock Source*/
#if (CLK_SOURCE == AHB)
  SET_BIT(SYS->CTRL, PIN2);
#elif (CLK_SOURCE == AHB_DIV_8)
  CLR_BIT(SYS->CTRL, PIN2);
#endif

// Choose SYSTICK INT enable
#if SYSTICK_INTERIPET == ENABLE // Enable Interrupt
  SET_BIT(SYS->CTRL, PIN1);
#elif SYSTICK_INTERIPET == DISABLE
  CLR_BIT(SYS->CTRL, PIN1);
#endif

  // Choose SYSTICK Down Counter enable

#if SYSTICK_ENABLE == ENABLE
  SET_BIT(SYS->CTRL, PIN0);
#elif SYSTICK_ENABLE == DISABLE
  CLR_BIT(SYS->CTRL, PIN0);
#endif
}
void mSYSTK_voidEnableSysTick(void)
{
  SET_BIT(SYS->CTRL, 0);
}
void mSYSTK_voidDisableSysTick(void)
{

  CLR_BIT(SYS->CTRL, 0);
}

u32 mSYSTICK_u32GetElapsedTime(void)
{
  u32 Local_u32ElapsedTime;
  Local_u32ElapsedTime = SYS->LOAD - SYS->VAL;
  return Local_u32ElapsedTime;
}

u32 mSYSTICK_u32GetRemainingTime(void)
{
  u32 Local_u32RemainingTime;
  Local_u32RemainingTime = SYS->VAL;
  return Local_u32RemainingTime;
}
void mSYSTICK_voidBusyWait(u32 Copy_u32TimeWait) // Cleared by H/W when count finished
{
  SYS->LOAD = Copy_u32TimeWait;
  u32 RegisterValue = GET_BIT(SYS->CTRL, PIN16);
  while (RegisterValue == 0)
  {
    // Wait
  }
  SYS->VAL = 0;
}

void mSYSTICK_voidSetPreLoadValue(u32 Copy_u8LoadValue)
{
  SYS->LOAD = Copy_u8LoadValue;
}

void mSYSTICK_voidResetSysTick(void)
{
  SYS->VAL = 0;
}

/**********************************************************************************/
// void MSTK_voidSetSingleInterval(void (*NotificationFunction)(void))
// {
// 	pvCallBackFunction = NotificationFunction;
// 	u8IntervalFlag = SINGLE_INTERVAL;
// }

// void MSTK_voidSetPeriodicInterval(void (*NotificationFunction)(void))
// {
// 	pvCallBackFunction = NotificationFunction;
// 	u8IntervalFlag = PERIODIC_INTERVAL;
// }

// void SysTick_Handler(void)
// {
// 	u32 Local_u32TempVar;
// 	if(u8IntervalFlag == SINGLE_INTERVAL)
// 	{
// 		STK->LOAD = 0;
// 		STK->VAL = 0;
// 		CLR_BIT(STK->CTRL, 0);
// 	}
// 	if(pvCallBackFunction != NULL)
// 	{
// 		pvCallBackFunction();
// 	}
// 	Local_u32TempVar = GET_BIT(STK->CTRL, 16);
// }
