/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        7 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

// SET pin Mode input-output-Alternative-Analoge

void mGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{

    switch (Copy_u8Port)
    {

    case GPIO_A:
        switch (Copy_u8Mode)
        {
        case INPUT:
            GPIOA_REG->GPIOx_MODER |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case OUTPUT:
            GPIOA_REG->GPIOx_MODER |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case ALTERNATIVE:
            GPIOA_REG->GPIOx_MODER |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case ANALOG:
            GPIOA_REG->GPIOx_MODER |= (0b11 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }
    case GPIO_B:
        switch (Copy_u8Mode)
        {
        case INPUT:
            GPIOB_REG->GPIOx_MODER |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case OUTPUT:
            GPIOB_REG->GPIOx_MODER |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case ALTERNATIVE:
            GPIOB_REG->GPIOx_MODER |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case ANALOG:
            GPIOB_REG->GPIOx_MODER |= (0b11 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }
    case GPIO_C:
        switch (Copy_u8Mode)
        {
        case INPUT:
            GPIOC_REG->GPIOx_MODER |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case OUTPUT:
            GPIOC_REG->GPIOx_MODER |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case ALTERNATIVE:
            GPIOC_REG->GPIOx_MODER |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case ANALOG:
            GPIOC_REG->GPIOx_MODER |= (0b11 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }
    }
}

void mGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{

    switch (Copy_u8Port)
    {

    case GPIO_A:
        if (Copy_u8OutputType == OPEN_DRAIN)
        {
            SET_BIT(GPIOA_REG->GPIOx_OTYPER, Copy_u8PinNumber);
        }
        else if (Copy_u8OutputType == PUSH_PULL)
        {
            CLR_BIT(GPIOA_REG->GPIOx_OTYPER, Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIO_B:
        if (Copy_u8OutputType == OPEN_DRAIN)
        {
            SET_BIT(GPIOB_REG->GPIOx_OTYPER, Copy_u8PinNumber);
        }
        else if (Copy_u8OutputType == PUSH_PULL)
        {
            CLR_BIT(GPIOB_REG->GPIOx_OTYPER, Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIO_C:
        if (Copy_u8OutputType == OPEN_DRAIN)
        {
            SET_BIT(GPIOC_REG->GPIOx_OTYPER, Copy_u8PinNumber);
        }
        else if (Copy_u8OutputType == PUSH_PULL)
        {
            CLR_BIT(GPIOC_REG->GPIOx_OTYPER, Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    default:
        /* ERROR */
        break;
    }
}

void mGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{

    switch (Copy_u8Port)
    {
    case GPIO_A:
        switch (Copy_u8OutputSpeed)
        {
        case LOW_SPEED: // 2 MHZ
            GPIOA_REG->GPIOx_OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case MED_SPEED: // 10 MHZ
            GPIOA_REG->GPIOx_OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case HIGH_SPEED: // 50 MHZ
            GPIOA_REG->GPIOx_OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case VERY_HIGH_SPEED: // 200 MHZ
            GPIOA_REG->GPIOx_OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }

    case GPIO_B:
        switch (Copy_u8OutputSpeed)
        {
        case LOW_SPEED: // 2 MHZ
            GPIOB_REG->GPIOx_OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case MED_SPEED: // 10 MHZ
            GPIOB_REG->GPIOx_OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case HIGH_SPEED: // 50 MHZ
            GPIOB_REG->GPIOx_OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case VERY_HIGH_SPEED: // 200 MHZ
            GPIOB_REG->GPIOx_OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }

    case GPIO_C:
        switch (Copy_u8OutputSpeed)
        {
        case LOW_SPEED: // 2 MHZ
            GPIOC_REG->GPIOx_OSPEEDR |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case MED_SPEED: // 10 MHZ
            GPIOC_REG->GPIOx_OSPEEDR |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case HIGH_SPEED: // 50 MHZ
            GPIOC_REG->GPIOx_OSPEEDR |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case VERY_HIGH_SPEED: // 200 MHZ
            GPIOC_REG->GPIOx_OSPEEDR |= (0b11 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }
    }
}

void mGPIO_voidSetConnectionType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8ConnectionType)
{
    switch (Copy_u8Port)
    {
    case GPIO_A:

        switch (Copy_u8ConnectionType)
        {
        case FLOAT:
            GPIOA_REG->GPIOx_PUPDR |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case PULL_UP:
            GPIOA_REG->GPIOx_PUPDR |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case PULL_DOWN:
            GPIOA_REG->GPIOx_PUPDR |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }

    case GPIO_B:
        switch (Copy_u8ConnectionType)
        {
        case FLOAT:
            GPIOB_REG->GPIOx_PUPDR |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case PULL_UP:
            GPIOB_REG->GPIOx_PUPDR |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case PULL_DOWN:
            GPIOB_REG->GPIOx_PUPDR |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }

    case GPIO_C:
        switch (Copy_u8ConnectionType)
        {
        case FLOAT:
            GPIOC_REG->GPIOx_PUPDR |= (0b00 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case PULL_UP:
            GPIOC_REG->GPIOx_PUPDR |= (0b01 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        case PULL_DOWN:
            GPIOC_REG->GPIOx_PUPDR |= (0b10 << (Copy_u8PinNumber * PIN_OFFSET));
            break;
        default:
            /* ERROR */
            break;
        }
    }
}
void mGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    /*Check For The Port Name*/
    switch (Copy_u8Port)
    {
    case GPIO_A:
        /*Check For The Value Of The Pin*/
        switch (Copy_u8PinValue)
        {
        case LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOA_REG->GPIOx_BSRR = 1 << (Copy_u8PinNumber + 16);
            break;
        case HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOA_REG->GPIOx_BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;

    case GPIO_B:
        /*Check For The Value Of The Pin*/
        switch (Copy_u8PinValue)
        {
        case LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOB_REG->GPIOx_BSRR = 1 << (Copy_u8PinNumber + 16);
            break;
        case HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOB_REG->GPIOx_BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;

    case GPIO_C:
        /*Check For The Value Of The Pin*/
        switch (Copy_u8PinValue)
        {
        case LOW:
            /*Set The Output Pin To Be Low, Atomic Reset*/
            GPIOC_REG->GPIOx_BSRR = 1 << (Copy_u8PinNumber + 16);
            break;
        case HIGH:
            /*Set The Output Pin To Be High, Atomic Set*/
            GPIOC_REG->GPIOx_BSRR = 1 << (Copy_u8PinNumber);
            break;
        }
        break;
    }
}

u8 mGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber)
{
    u8 Local_u8PinValue;
    /*Check For The Port Name*/
    switch (Copy_u8Port)
    {
    case GPIO_A:
        /*Assign The Pin Value For The Local_u8PinValue Variable*/
        Local_u8PinValue = GET_BIT(GPIOA_REG->GPIOx_IDR, Copy_u8PinNumber);
        break;

    case GPIO_B:
        /*Assign The Pin Value For The Local_u8PinValue Variable*/
        Local_u8PinValue = GET_BIT(GPIOB_REG->GPIOx_IDR, Copy_u8PinNumber);
        break;

    case GPIO_C:
        /*Assign The Pin Value For The Local_u8PinValue Variable*/
        Local_u8PinValue = GET_BIT(GPIOC_REG->GPIOx_IDR, Copy_u8PinNumber);
        break;
    }
    /*Return The Pin Value*/
    return Local_u8PinValue;
}
void mGPIO_voidSetPortSpecificMode(u8 Copy_u8Port, u32 Copy_u32PortModeValue)
{
    /*Check For The Port Name*/
    switch (Copy_u8Port)
    {
    case GPIO_A:
        /*Set The Specific Mode Value To MODE Register*/
        GPIOA_REG->GPIOx_MODER = Copy_u32PortModeValue;
        break;

    case GPIO_B:
        /*Set The Specific Mode Value To MODE Register*/
        GPIOA_REG->GPIOx_MODER = Copy_u32PortModeValue;
        break;

    case GPIO_C:
        /*Set The Specific Mode Value To MODE Register*/
        GPIOA_REG->GPIOx_MODER = Copy_u32PortModeValue;
        break;
    }
}
void mGPIO_voidSetPortSpecificValue(u8 Copy_u8Port, u32 Copy_u32PortValue)
{
    /*Check For The Port Name*/
    switch (Copy_u8Port)
    {
    case GPIO_A:
        /*Set The Specific Value To ODR Register*/
        GPIOA_REG->GPIOx_ODR = Copy_u32PortValue;
        break;

    case GPIO_B:
        /*Set The Specific Value To ODR Register*/
        GPIOA_REG->GPIOx_ODR = Copy_u32PortValue;
        break;

    case GPIO_C:
        /*Set The Specific Value To ODR Register*/
        GPIOA_REG->GPIOx_ODR = Copy_u32PortValue;
        break;
    }
}

void mGPIO_voidSetPinValueODR(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
    switch (Copy_u8Port)
    {

    case GPIO_A:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOA_REG->GPIOx_ODR, Copy_u8PinNumber);
        }
        else if (Copy_u8PinValue == LOW)
        {
            CLR_BIT(GPIOA_REG->GPIOx_ODR, Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIO_B:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOB_REG->GPIOx_ODR, Copy_u8PinNumber);
        }
        else if (Copy_u8PinValue == LOW)
        {
            CLR_BIT(GPIOB_REG->GPIOx_ODR, Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

    case GPIO_C:
        if (Copy_u8PinValue == HIGH)
        {
            SET_BIT(GPIOC_REG->GPIOx_ODR, Copy_u8PinNumber);
        }
        else if (Copy_u8PinValue == LOW)
        {
            CLR_BIT(GPIOC_REG->GPIOx_ODR, Copy_u8PinNumber);
        }
        else
        {
            /* ERROR */
        }
        break;

   
    }
}
