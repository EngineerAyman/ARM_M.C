/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        14 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         HAL
 ********************************************/

#ifndef LEDMX_CONFIG_H_
#define LEDMX_CONFIG_H_

// u8 ROWARRAY[16]={}

#define     HLEDMX_ROW_PORT    GPIO_A
#define     HLEDMX_COL_PORT    GPIO_B



// ROW CONFIG
#define     HLEDMX_R0_PIN    PIN0
#define     HLEDMX_R1_PIN    PIN1
#define     HLEDMX_R2_PIN    PIN2
#define     HLEDMX_R3_PIN    PIN3
#define     HLEDMX_R4_PIN    PIN4
#define     HLEDMX_R5_PIN    PIN5
#define     HLEDMX_R6_PIN    PIN6
#define     HLEDMX_R7_PIN    PIN7


// COL CONFIG
#define     HLEDMX_C0_PIN    PIN0
#define     HLEDMX_C1_PIN    PIN1
#define     HLEDMX_C2_PIN    PIN2
#define     HLEDMX_C3_PIN    PIN3
#define     HLEDMX_C4_PIN    PIN4
#define     HLEDMX_C5_PIN    PIN5
#define     HLEDMX_C6_PIN    PIN6
#define     HLEDMX_C7_PIN    PIN7


#endif 
