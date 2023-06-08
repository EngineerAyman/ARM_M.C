/*********************************************
 * Author:               AYMAN HARRAZ
 * Creation Data:        14 MAY, 2023
 * Version:              v1.0
 * Compiler:             GNU ARM GCC
 * Controller:		     STM32F401CCU6 (32-bit Architecture)
 * Processor:		     Cortex M4 (32-bit Architecture)
 * Layer:		         HAL
 ********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMX_interface.h"
#include "LEDMX_private.h"
#include "LEDMX_config.h"


void hLEDMX_voidInit(void)
{
/* INIT ROW AND COLUM TO BE OUTPUT */
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R0_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R1_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R2_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R3_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R4_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R5_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R6_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_ROW_PORT,HLEDMX_R7_PIN,OUTPUT);


/* INIT COL */
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C0_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C1_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C2_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C3_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C4_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C5_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C6_PIN,OUTPUT);
mGPIO_voidSetPinMode(HLEDMX_COL_PORT,HLEDMX_C7_PIN,OUTPUT);

/* Disable All column */
voidDisplayAllColumns();
}




void hLEDMX_voidDisplay(u8 * Copy_pu8Data)
{

u8 Local_u8ColumnIndex=0;
u8 Local_u8RowIndex=0;
u8 Local_u8BIT=0;
static u8 RowsArr[8]={HLEDMX_R0_PIN,HLEDMX_R1_PIN,HLEDMX_R2_PIN,HLEDMX_R3_PIN,HLEDMX_R4_PIN,HLEDMX_R5_PIN,HLEDMX_R6_PIN,HLEDMX_R7_PIN};
static u8 ColsArr[8]={HLEDMX_C0_PIN,HLEDMX_C1_PIN,HLEDMX_C2_PIN,HLEDMX_C3_PIN,HLEDMX_C4_PIN,HLEDMX_C5_PIN,HLEDMX_C6_PIN,HLEDMX_C7_PIN};

for (Local_u8ColumnIndex= 0;Local_u8ColumnIndex < 8; Local_u8ColumnIndex++)
{
	voidDisplayAllColumns();
    for (Local_u8RowIndex= 0;Local_u8RowIndex < 8; Local_u8RowIndex++)
     {
          Local_u8BIT=GET_BIT(Copy_pu8Data[Local_u8ColumnIndex],Local_u8RowIndex);
		  mGPIO_voidSetPinValue(HLEDMX_ROW_PORT,RowsArr[Local_u8RowIndex],Local_u8BIT);
	 }
	mGPIO_voidSetPinValue(HLEDMX_COL_PORT,ColsArr[Local_u8ColumnIndex],LOW);
	/* 2.5 msec cause 1/50 */
	 mSYSTICK_voidBusyWait(2500);
}

}


static void voidDisplayAllColumns(void)
{

mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C0_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C1_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C2_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C3_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C4_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C5_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C6_PIN,HIGH);
mGPIO_voidSetPinValue(HLEDMX_COL_PORT,HLEDMX_C7_PIN,HIGH);


}
