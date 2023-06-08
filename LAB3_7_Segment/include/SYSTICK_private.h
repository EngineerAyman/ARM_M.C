/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        9 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define AHB             0
#define AHB_DIV_8       1

typedef struct
{

    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;

} SYSTICK_t;

#define SYS ((volatile SYSTICK_t *)0xE00E010)

#endif