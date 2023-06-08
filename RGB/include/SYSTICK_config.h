/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        9 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/

#ifndef SYSTICK_CONFIG_H
#define SYSTICK_CONFIG_H

/*  Choose CLK source selection */
/*Option
* AHB 
* AHB_DIV_8  
*/
#define  CLK_SOURCE    AHB_DIV_8

/* OPTIONS
* ENABLE 
* DISABLE
*/
#define SYSTICK_ENABLE         ENABLE
#define SYSTICK_INTERIPET      DISABLE 










#endif