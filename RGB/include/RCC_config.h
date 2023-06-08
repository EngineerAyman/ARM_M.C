/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        3 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_
#define HSI 0
#define HSE 1
#define PLL 2

#define     CPU_CLK_SOURCE      HSI
#define     PLL_SOURCE          HSI


/* Choose Prescaler */
#define    AHB_PRESCALER           SYSCLOCK_DEVIDED_BY_1
#define    APB1_PRESCALER          APB1_2_DEVID_BY2
#define    APB2_PRESCALER          APB1_2_DEVID_BY2


#endif 
