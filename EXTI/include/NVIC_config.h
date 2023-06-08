/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        9 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/*  OPTIONS
*   GROUP_4_SUB_0_BITS   
*   GROUP_3_SUB_1_BITS   
*   GROUP_2_SUB_2_BITS   
*   GROUP_1_SUB_3_BITS   
*   GROUP_0_SUB_4_BITS  
*/  


#define   NVIC_GROUP_SUB_DISTRIBUTION    GROUP_2_SUB_2_BITS

/* OPTIONS
* ENABLE 
* DISABLE
*/
#define SYSTICK_ENABLE         ENABLE
#define SYSTICK_INTERIPET      ENABLE 










#endif
