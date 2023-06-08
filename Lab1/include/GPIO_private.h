/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        7 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define  PIN_OFFSET    2 



typedef struct 
{

    volatile u32 GPIOx_MODER;       // Input-output-Alternative-Analoge
    volatile u32 GPIOx_OTYPER;      // Output Push pull or Open drain
    volatile u32 GPIOx_OSPEEDR;     // 2 bits low-mediuem-high-veryhigh
    volatile u32 GPIOx_PUPDR;       // pull up -pull down Reg
    volatile u32 GPIOx_IDR;         // Input Data Reg read only Reg
    volatile u32 GPIOx_ODR;         // output data reg for set and reset
    volatile u32 GPIOx_BSRR;        // output data reg for set 0:15 and reset 16:31
    volatile u32 GPIOx_LCKR;        // Lock Reg for stop any changes at any bin
    volatile u32 GPIOx_AFRL;        // alternate function low register
    volatile u32 GPIOx_AFRH;        // alternate function high register

}GPIO_t;


//Reg definition for GPIO adress Pointers to Struct 
#define        GPIOA_REG          ((volatile GPIO_t * )0x40020000)
#define        GPIOB_REG          ((volatile GPIO_t * )0x40020400)
#define        GPIOC_REG          ((volatile GPIO_t * )0x40020800)







#endif