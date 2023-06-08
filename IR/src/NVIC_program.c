/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        20 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		                 MCAL
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


#define  NVIC_EXTI0     6
#define  NVIC_EXTI1     7




void mNVIC_voidInit(void)
{
   /* Set number of group and sub*/
 SCB_AIRCR  |= ((AIRCR_PRIVKEY << 16) | (NVIC_GROUP_SUB_DISTRIBUTION << 8));

}
void mNVIC_voidEnablePeripheralINT(u8 Copy_u8Perepheral_ID)
{
  u8 Local_u8ISERindex;
  Local_u8ISERindex = Copy_u8Perepheral_ID /32;
  NVIC -> ISER[Local_u8ISERindex] = (1 <<Copy_u8Perepheral_ID % 32);
}
void mNVIC_voidDisablePeripheralINT(u8 Copy_u8Perepheral_ID)
{
  u8 Local_u8ISERindex;
  Local_u8ISERindex = Copy_u8Perepheral_ID /32;
  NVIC -> ICER[Local_u8ISERindex] = (1 <<Copy_u8Perepheral_ID % 32);
}
void mNVIC_voidSetPendingFlag(u8 Copy_u8Perepheral_ID)
{
  u8 Local_u8ISERindex;
  Local_u8ISERindex = Copy_u8Perepheral_ID /32;
  NVIC -> ISPR[Local_u8ISERindex] = (1 <<Copy_u8Perepheral_ID % 32);
}
void mNVIC_voidClearPendingFlag(u8 Copy_u8Perepheral_ID)
{
  u8 Local_u8ISERindex;
  Local_u8ISERindex = Copy_u8Perepheral_ID /32;
  NVIC -> ICPR[Local_u8ISERindex] = (1 <<Copy_u8Perepheral_ID % 32);

}
u8   mNVIC_u8GetActiveFlag(u8 Copy_u8Perepheral_ID);
void mNVIC_voidSetPeripheralPeriority(u8 Copy_u8Perepheral_ID,u8 Copy_u8Periority)
{

   NVIC -> IPR [1 <<Copy_u8Perepheral_ID ] = (Copy_u8Periority << 4);  
 
}

