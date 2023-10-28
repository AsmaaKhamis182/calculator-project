#include "Std_types.h"
#include "Bit_utils.h"
#include "PORT.h"
#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "KEYPAD_cfg.h"
#include "KEYPAD_prv.h"
void KEYPAD_voidInit(void)
{
	PORT_enumSET_PINDirection(ROW0PIN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(ROW1PIN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(ROW2PIN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(ROW3PIN, PORT_u8PINDIR_OUTPUT);
	
	PORT_enumSET_PINMODE(ROW0PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	PORT_enumSET_PINMODE(ROW1PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	PORT_enumSET_PINMODE(ROW2PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	PORT_enumSET_PINMODE(ROW3PIN, PORT_u8PINMODE_OUTPUT_HIGH);
	
	PORT_enumSET_PINDirection(COLOUMN0PIN, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINDirection(COLOUMN1PIN, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINDirection(COLOUMN2PIN, PORT_u8PINDIR_INPUT);
	PORT_enumSET_PINDirection(COLOUMN3PIN, PORT_u8PINDIR_INPUT);	
	
	PORT_enumSET_PINMODE(COLOUMN0PIN, PORT_u8PINMODE_INPUUT_PULLUP);
	PORT_enumSET_PINMODE(COLOUMN1PIN, PORT_u8PINMODE_INPUUT_PULLUP);
	PORT_enumSET_PINMODE(COLOUMN2PIN, PORT_u8PINMODE_INPUUT_PULLUP);
	PORT_enumSET_PINMODE(COLOUMN3PIN, PORT_u8PINMODE_INPUUT_PULLUP);

}
u8 KEYPAD_voidGetKEYPADVal(void)
{
	u8 KEYPAD_u8ColoumnVal;
	volatile u8 KEYPAD_u8Flag = 0;
	for(u8 i=0;i<4;i++)
	{
		DIO_enum_WriteChannel(KEYPAD_u8ROWSArray[i], DIO_u8LOW);
		for(u8 m=0;m<4;m++)
		{
			DIO_enum_ReadChannel (KEYPAD_u8COLOUMNSSArray[m], &KEYPAD_u8ColoumnVal);
			if(KEYPAD_u8ColoumnVal == DIO_u8LOW)
			{
				while(KEYPAD_u8ColoumnVal == DIO_u8LOW)
				{
					DIO_enum_ReadChannel (KEYPAD_u8COLOUMNSSArray[m], &KEYPAD_u8ColoumnVal);
				}
				KEYPAD_u8Flag = 1;
			}
			if(KEYPAD_u8Flag == 1 )
			{

				DIO_enum_WriteChannel(KEYPAD_u8ROWSArray[i], DIO_u8High);
				return KEYPAD_u8arrayVals[i][m];
			}
		}
		DIO_enum_WriteChannel(KEYPAD_u8ROWSArray[i], DIO_u8High);
	}
	return 0;
}

