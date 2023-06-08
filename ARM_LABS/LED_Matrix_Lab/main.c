#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "LEDMX_interface.h"

int main(void)
{
	u8 arr[]={
					0x00,   /* 0 */
					0x14,   /* 1 */
					0x00,   /* 2 */
					0x00,   /* 3 */
					0x00,   /* 4 */
					0x00,   /* 5 */
					0x00,   /* 6 */
					0x00,   /* 7 */
					0x00,   /* 8 */

	          };

	mRCC_voidInit();

	mSYSTICK_voidInit();

	hLEDMX_voidInit();

	mRCC_voidEnablePeripheralClock(RCC_AHB1,GPIO_A);
	mRCC_voidEnablePeripheralClock(RCC_AHB1,GPIO_B);
	while(1)
	{
		hLEDMX_voidDisplay(&arr);
	}

}
