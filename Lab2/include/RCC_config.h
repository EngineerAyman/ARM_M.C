/*********************************************
 * Author:          AYMAN HARRAZ
 * Creation Data:   3 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM GCC
 ********************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

#define     CPU_CLK_SOURCE      HSI
#define     PLL_SOURCE          HSI


/* Choose Prescaler */
#define    AHB_PRESCALER           SYSCLOCK_DEVIDED_BY_2
#define    APB1_PRESCALER          APB1_2_DEVID_BY2
#define    APB2_PRESCALER          APB1_2_DEVID_BY2


#endif 
