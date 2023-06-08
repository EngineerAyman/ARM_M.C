/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        22 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define    EXTI_RISING_EDGE     0
#define    EXTI_FALING_EDGE     1
#define    EXTI_ONCHANGE_EDGE   2


void mEXTI_voidInit(void);
void mEXTI_voidEnableINT(u8 Copy_u8EXTINTLine);
void mEXTI_voidDisableINT(u8 Copy_u8EXTINTLine);
void mEXTI_voidChangeSenseMode(u8 Copy_u8EXTINTLine,u8 Copy_u8SenseSignal);
void mEXTI_voidSetCallBack(u8 Copy_u8EXTINTLine,void (*pvNotificationFunction)(void));




#endif