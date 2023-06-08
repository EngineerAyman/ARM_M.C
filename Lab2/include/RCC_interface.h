/*********************************************
 * Author:          AYMAN HARRAZ
 * Creation Data:   3 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM GCC
 ********************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define     RCC_AHB1        0
#define     RCC_AHB2        1
#define     RCC_APB1        2
#define     RCC_APB2        3

#define     RCC_GPIOA       0
#define     RCC_GPIOB       1
#define     RCC_GPIOC       2

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);




#endif 
