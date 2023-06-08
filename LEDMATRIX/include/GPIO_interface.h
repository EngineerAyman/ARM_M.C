/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        7 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         MCAL
 ********************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


#define GPIO_A                           0
#define GPIO_B                           1
#define GPIO_C                           2

#define PIN0                            0
#define PIN1                            1
#define PIN2                            2
#define PIN3                            3
#define PIN4                            4
#define PIN5                            5
#define PIN6                            6
#define PIN7                            7
#define PIN8                            8
#define PIN9                            9
#define PIN10                           10
#define PIN11                           11
#define PIN12                           12
#define PIN13                           13
#define PIN14                           14
#define PIN15                           15

// FOR Mode REG
#define INPUT                           0     
#define OUTPUT                          1     
#define ALTERNATIVE                     2     
#define ANALOG                          3    

// FOR OUTPUT SPEED REG
#define LOW_SPEED                       0
#define MED_SPEED                       1
#define HIGH_SPEED                      2
#define VERY_HIGH_SPEED                 3

// FOR OUTPUT TYPE REG
#define PUSH_PULL                       0
#define OPEN_DRAIN                      1

// FOR OUTPUT DATA REG
#define HIGH                            1
#define LOW                             0

// FOR PUPDR REG 

#define     FLOAT                       0
#define     PULL_UP                     1
#define     PULL_DOWN                   2
#define     RESERVED                    3


void mGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8Mode);
void mGPIO_voidSetOutputType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputType);
void mGPIO_voidSetOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);
void mGPIO_voidSetConnectionType(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8ConnectionType);
void mGPIO_voidSetPinValueODR(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
void mGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
  u8 mGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8PinNumber);
void mGPIO_voidSetPortSpecificMode(u8 Copy_u8port, u32 Copy_u32PortModeValue);
void mGPIO_voidSetPortSpecificValue(u8 Copy_u8port, u32 Copy_u32PortValue);
#endif
