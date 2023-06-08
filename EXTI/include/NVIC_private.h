/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        20 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		                 MCAL
 ********************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
/*  GROUP && SUB */

#define   GROUP_4_SUB_0_BITS    0b000
#define   GROUP_3_SUB_1_BITS    0b100
#define   GROUP_2_SUB_2_BITS    0b101
#define   GROUP_1_SUB_3_BITS    0b110
#define   GROUP_0_SUB_4_BITS    0b111

/* KEY*/
#define AIRCR_PRIVKEY   0x05FA

typedef struct
{

    volatile u32 ISER[8];                // for  0 : 7 ALL 4 BITS 
    volatile u32 Reserved0[24];         // for 0x180 - 0x11C  = 25 decimal 
    volatile u32 ICER[8];
    volatile u32 Reserved1[24];
    volatile u32 ISPR[8];
    volatile u32 Reserved2[24];
    volatile u32 ICPR[8];
    volatile u32 Reserved3[24];
    volatile u32 IABR[8];
    volatile u32 Reserved4[56];
    volatile u8  IPR[240];
    volatile u32 Reserved5[580];
    volatile u32 STIR;

} NVIC_t;


#define     NVIC         ((volatile NVIC_t *)0xE000E100)
#define     SCB_AIRCR    *((volatile u32 *)0xE000ED0C)


#endif
