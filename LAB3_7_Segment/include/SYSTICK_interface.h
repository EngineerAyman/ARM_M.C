/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        9 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7
#define PIN8         8
#define PIN9         9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15
#define PIN16       16
#define PIN17       17
#define PIN18       18
#define PIN19       19
#define PIN20       20
#define PIN21       21
#define PIN22       22
#define PIN23       23

#define ENABLE            1
#define DISABLE           0



void mSYSTICK_voidInit(void);
u32 mSYSTICK_u32GetElapsedTime(void);
u32 mSYSTICK_u32GetRemainingTime(void);
void mSYSTICK_voidBusyWait(u32 Copy_u32TimeWait);
void mSYSTICK_voidSetPreLoadValue(u32 Copy_u8LoadValue);
void mSYSTICK_voidResetSysTick(void);

#endif