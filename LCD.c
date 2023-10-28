#include "Std_types.h"
#include "Bit_utils.h"
#include<util/delay.h>

#include "DIO_int.h"
#include "PORT.h"
#include "LCD.h"

void LCD_voidInit(void)
{
	PORT_enumSET_PINDirection(RS, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(EN, PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(D4 , PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(D5 , PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(D6 , PORT_u8PINDIR_OUTPUT);
	PORT_enumSET_PINDirection(D7 , PORT_u8PINDIR_OUTPUT);
	_delay_ms (30);

	LCD_voidSendCommand(LCD_RETURN_HOME);
	_delay_ms (15);
	LCD_voidSendCommand(FunctionSet1_Command);
	DIO_enum_WriteChannel(EN, DIO_u8High);

	DIO_enum_WriteChannel(D4, GET_BIT(FunctionSet2_Command,4));
	DIO_enum_WriteChannel(D5, GET_BIT(FunctionSet2_Command,5));
	DIO_enum_WriteChannel(D6, GET_BIT(FunctionSet2_Command,6));
	DIO_enum_WriteChannel(D7, GET_BIT(FunctionSet2_Command,7));
	
	DIO_enum_WriteChannel(EN, DIO_u8LOW);
	_delay_ms (1);
	LCD_voidSendCommand(LCD_DISPLAY_ON);
	_delay_ms (1);
	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms (15);
	LCD_voidSendCommand(LCD_ENTRY_MODE);
	_delay_ms (2);

}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_enum_WriteChannel(RS, DIO_u8LOW);
	LCD_voidSendDataBus(Copy_u8Command);
}
void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_enum_WriteChannel(RS, DIO_u8High);
	LCD_voidSendDataBus(Copy_u8Data);
}
void LCD_voidSendDataBus(u8 Copy_u8BUS)
{
	DIO_enum_WriteChannel(EN, DIO_u8High);

	DIO_enum_WriteChannel(D7, GET_BIT(Copy_u8BUS,7));
	DIO_enum_WriteChannel(D6, GET_BIT(Copy_u8BUS,6));
	DIO_enum_WriteChannel(D5, GET_BIT(Copy_u8BUS,5));
	DIO_enum_WriteChannel(D4, GET_BIT(Copy_u8BUS,4));
	
	DIO_enum_WriteChannel(EN, DIO_u8LOW);
	_delay_us (5);
	DIO_enum_WriteChannel(EN, DIO_u8High);

	DIO_enum_WriteChannel(D7, GET_BIT(Copy_u8BUS,3));
	DIO_enum_WriteChannel(D6, GET_BIT(Copy_u8BUS,2));
	DIO_enum_WriteChannel(D5, GET_BIT(Copy_u8BUS,1));
	DIO_enum_WriteChannel(D4, GET_BIT(Copy_u8BUS,0));
	
	DIO_enum_WriteChannel(EN, DIO_u8LOW);
	_delay_us (5);

}
void LCD_voidWriteChar(u8 Copy_u8Character)
{
	DIO_enum_WriteChannel(RS, DIO_u8High);
	LCD_voidSendDataBus(Copy_u8Character);	
}
void LCD_voidWriteString(pu8 Ptr_u8String)
{
	u8 Local_u8Counter = 0;
	while(Ptr_u8String[Local_u8Counter] != '\0')
	{
		LCD_voidWriteChar(Ptr_u8String[Local_u8Counter]);
		Local_u8Counter++;
		_delay_us (2);
	}
	
}
void LCD_voidWriteNumbers(f32 Copy_f32Number)
{
	u8 Local_u8Array[20];
	u32 Local_f32Number = (u32)(Copy_f32Number*100);
	s8 Local_s8Counter = 0;
	//Local_f32Number*=100;
	while (Local_f32Number != 0)
	{
		Local_u8Array[Local_s8Counter] = Local_f32Number%10;
		Local_f32Number/=10;
		Local_s8Counter++;
	}
	while(Local_s8Counter>0)
	{
		if(Local_s8Counter == 2)
		{
			LCD_voidWriteChar('.');
		}
		Local_s8Counter--;
		LCD_voidWriteChar(Local_u8Array[Local_s8Counter]+'0');
		_delay_us (2);

	}
}
void LCD_voidSetCursorToX_y(u8 Copy_u8Row,u8 Copy_u8Coloumn)
{
	switch(Copy_u8Row)
	{
		case LCD_ROW0:
			LCD_voidSendCommand(0x80+Copy_u8Coloumn);
			break;
		case LCD_ROW1:
			LCD_voidSendCommand(0x80+0x40+Copy_u8Coloumn);
			break;
		case LCD_ROW2:
			LCD_voidSendCommand(0x80+0x40+0x14+Copy_u8Coloumn);
			break;

		case LCD_ROW3:
			LCD_voidSendCommand(0x80+0x40+0x14+0x54+Copy_u8Coloumn);
			break;
	}
}
void LCD_voidCreateCustomChar(u8 CharID,u8 *Copy_CustomChar)
{
	LCD_voidSendCommand(CG_RAM_ADDRESS + CharID);
	for(u8 i=0;i<8;i++)
	{
		LCD_voidSendData(Copy_CustomChar[i]);
	}

}
