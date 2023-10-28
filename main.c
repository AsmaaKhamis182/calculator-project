
#include "Std_types.h"
#include "Bit_utils.h"


#include "PORT.h"
#include "DIO_int.h"

#include "LCD.h"

#include "KEYPAD_int.h"
f32 operation(u8 ID, u32 OP1, u32 OP2);

int main(void)
{
	PORT_voidInit();
	LCD_voidInit();
	KEYPAD_voidInit();
	LCD_voidInit();
	u8 data =0;
	u8 flag = 0;
	u8 operatonID = 0;
	u32 operand1=0;
	u32 operand2=0;
	f32 result;
	while(1)
	{
		data = KEYPAD_voidGetKEYPADVal();
		//LCD_voidSetCursorToX_y(LCD_ROW0,LCD_Coloumn0);
		if(data != 0)
		{
			LCD_voidWriteChar(data);
			if((data != '+' && data != '-' && data != '*' && data != '/' && data != '=' && data != '.') && flag == 0 )
			{
				operand1 = (operand1*10) + (data - '0');
			}
			else if((data != '+' && data != '-' && data != '*' && data != '/' && data != '=' && data != '.') && flag == 1 )
			{
				operand2 = (operand2*10) + (data - '0');
			}
			else if(data == '+')
			{
				operatonID = 1;
				flag = 1;
			}
			else if(data == '-')
			{
				operatonID = 2;
				flag = 1;
			}
			else if(data == '*')
			{
				operatonID = 3;
				flag = 1;
			}
			else if(data == '/')
			{
				operatonID = 4;
				flag = 1;
			}
			else if(data == '.')
			{
				LCD_voidSendCommand(LCD_CLEAR);
				operatonID = 0;
				flag = 0;
				operand1=0;
				operand2=0;
			}
			else if(data == '=')
			{
				result = operation(operatonID, operand1, operand2);
				operatonID = 0;
				flag = 0;
				operand1=0;
				operand2=0;
				LCD_voidWriteNumbers(result);
				LCD_voidWriteString(" ");
			}
		}

	}
	return 0;
}
f32 operation(u8 ID, u32 OP1, u32 OP2)
{
	f32 resul;
	switch(ID)
	{
		case 1:
			resul=(f32) OP1 + OP2;
			break;
		case 2:
			resul=(f32) OP1 - OP2;
			break;
		case 3:
			resul=(f32) OP1 * OP2;
			break;
		case 4:
			resul= (f32)OP1 / OP2;
			break;
	}
	return resul;
}
