/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        22 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		       STM32F401CCU6 (32-bit Architecture)
 * Processor:		         Cortex M4 (32-bit Architecture)
 * Layer:		             MCAL
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

// Array of pointer to fun
static void (*pvCallBackFunction[16])(void) = {{NULL}};

void mEXTI_voidInit(void)
{
}
void mEXTI_voidEnableINT(u8 Copy_u8EXTINTLine)
{
  if (Copy_u8EXTINTLine > 15)
  {
    return;
  }

  SET_BIT(EXTI->IMR, Copy_u8EXTINTLine);
}
void mEXTI_voidDisableINT(u8 Copy_u8EXTINTLine)
{
  if (Copy_u8EXTINTLine > 15)
  {
    return;
  }
  CLR_BIT(EXTI->IMR, Copy_u8EXTINTLine);
}
void mEXTI_voidChangeSenseMode(u8 Copy_u8EXTINTLine, u8 Copy_u8SenseSignal)
{
  switch (Copy_u8SenseSignal)
  {
  case EXTI_RISING_EDGE:
    CLR_BIT(EXTI->FTSR, Copy_u8EXTINTLine); // Clear the falling edge sense mode before set rising
    SET_BIT(EXTI->RTSR, Copy_u8EXTINTLine);
    break;
  case EXTI_FALING_EDGE:
    CLR_BIT(EXTI->RTSR, Copy_u8EXTINTLine);
    SET_BIT(EXTI->FTSR, Copy_u8EXTINTLine);
    break;
  case EXTI_ONCHANGE_EDGE:
    SET_BIT(EXTI->FTSR, Copy_u8EXTINTLine);
    SET_BIT(EXTI->RTSR, Copy_u8EXTINTLine);
    break;
  }
}
void mEXTI_voidSetCallBack(u8 Copy_u8EXTINTLine, void (*pvNotificationFunction)(void))
{

  pvCallBackFunction[Copy_u8EXTINTLine] = pvNotificationFunction;
}
// ISR
void EXTI0_IRQHandeler(void)
{
  if (pvCallBackFunction[0] != NULL)
  {
    pvCallBackFunction[0]();
  }
  SET_BIT(EXTI->PR,0);
}
