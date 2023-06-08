/*********************************************
 * Author:          AYMAN HARRAZ
 * Creation Data:   28 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H
 
// Functions Like Macro To Manipulate Over Specific Bit
#define     SET_BIT(REG_NAME, BIT_NUM)          (REG_NAME |= (1 << BIT_NUM))
#define     CLR_BIT(REG_NAME, BIT_NUM)          (REG_NAME &= (~(1 << BIT_NUM)))
#define     GET_BIT(REG_NAME, BIT_NUM)          ((REG_NAME >> BIT_NUM) & 0x01)
#define     TOG_BIT(REG_NAME, BIT_NUM)          (REG_NAME ^= (1 << BIT_NUM))

// Functions Like Macro To Manipulate Over Specific Register
#define     SET_REG(REG_NAME, VALUE)            (REG_NAME = VALUE)
#define     GET_REG(REG_NAME)                   (REG_NAME)
#define     CLR_REG(REG_NAME)                   (REG_NAME = 0x00)
#define     TOG_PORT(REG_NAME)                  (REG_NAME ^=0xFF)





#endif
