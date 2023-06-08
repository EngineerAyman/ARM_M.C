/*********************************************
 * Author:          AYMAN HARRAZ
 * Creation Data:   3 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM GCC
 ********************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

// Pointer to structure 
typedef struct
{

    volatile u32 CR;                // No need to put Reg Name cause Struct only for RCC
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;

}RCC_t;


// Base Adress    0x40023800
#define     RCC       ((volatile RCC_t*)(0x40023800))


/* Prescaler FOR APB1  and APB2 */

#define     APB1_2_DEVID_BY2        0
#define     APB1_2_DEVID_BY4        1
#define     APB1_2_DEVID_BY8        2

/* Prescaler FOR AHB */
/* System clock Options : HSI - HSE - PLL */

#define    SYSCLOCK_DEVIDED_BY_1     0           // No Prescaler
#define    SYSCLOCK_DEVIDED_BY_2     8           // Named this cause Bit mask
#define    SYSCLOCK_DEVIDED_BY_4     9 
#define    SYSCLOCK_DEVIDED_BY_8     10 
#define    SYSCLOCK_DEVIDED_BY_16    11    



#endif 
