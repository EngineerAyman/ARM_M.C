/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        3 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
 

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void mRCC_voidInit(void)
{
    #if     CPU_CLK_SOURCE == HSI
        /*Enable HSI*/
            SET_BIT(RCC -> CR,0);
        /*Select HSI As System Clock (CPU Clk Source)*/
            CLR_BIT(RCC -> CFGR, 0);
            CLR_BIT(RCC -> CFGR, 1);
    #elif   CPU_CLK_SOURCE == HSE
        /*Enable HSE*/
            SET_BIT(RCC->CR, 16);
        /*Select HSE As System Clock (CPU CLK Source)*/
            SET_BIT(RCC->CFGR, 0);
            CLR_BIT(RCC->CFGR, 1);
    #elif   CPU_CLK_SOURCE == PLL
        #if PLL_SOURCE == HSI
            /*Enable HSI*/
            SET_BIT(RCC -> CR,0);
            /*Select HSI As PLL Source*/
            
            /*Enable PLL*/
            /*Select PLL As System Clock (CPU CLK Source)*/
        #elif PLL_SOURCE == HSE
            /*Enable HSE*/
            /*Select HSE As PLL Source*/
            /*Enable PLL*/
            /*Select PLL As System Clock (CPU CLK Source)*/
        #else
            #error "RCC PLL_SOURCE Configuration Error"
        #endif
    #else
        #error "RCC CPU_CLK_SOURCE Configuration Error"
    #endif
    RCC -> CFGR |= (AHB_PRESCALER << 4 );
}

void mRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID)
{
    switch(Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR, Copy_u8PeriperhalID);
        break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR, Copy_u8PeriperhalID);
        break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR, Copy_u8PeriperhalID);
        break;
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR, Copy_u8PeriperhalID);
        break;
        default:
            // return error
        break;
    }
}

void mRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID)
{
    switch(Copy_u8PeripheralBus)
    {
        case RCC_AHB1:
            CLR_BIT(RCC->AHB1ENR, Copy_u8PeriperhalID);
        break;
        case RCC_AHB2:
            CLR_BIT(RCC->AHB2ENR, Copy_u8PeriperhalID);
        break;
        case RCC_APB1:
            CLR_BIT(RCC->APB1ENR, Copy_u8PeriperhalID);
        break;
        case RCC_APB2:
            CLR_BIT(RCC->APB2ENR, Copy_u8PeriperhalID);
        break;
        default:
            // return error
        break;
    }
}


    
