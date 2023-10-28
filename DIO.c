#include "Std_types.h"
#include "Bit_utils.h"

#include "DIO_int.h"
#include "DIO_prv.h"
#include "DIO_cfg.h"

DIO_enumErrStatus DIO_enum_WriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level)
{
	u8 Local_u8PINID = Copy_u8ChannelId%8;
	u8 Local_u8PORTID = Copy_u8ChannelId/8;
	DIO_enumErrStatus Local_enumErrStatus = DIO_enumOK;
	switch(Local_u8PORTID)
	{
		case DIO_u8PORTA:
			if(Copy_u8Level == DIO_u8High)
			{
				SET_BIT(PORTA,Local_u8PINID);
			}
			else if(Copy_u8Level == DIO_u8LOW)
			{
				CLR_BIT(PORTA,Local_u8PINID);
			}
			else
			{
				Local_enumErrStatus = DIO_enumLevelErr;
			}
			break;
		case DIO_u8PORTB:
			if(Copy_u8Level == DIO_u8High)
			{
				SET_BIT(PORTB,Local_u8PINID);
			}
			else if(Copy_u8Level == DIO_u8LOW)
			{
				CLR_BIT(PORTB,Local_u8PINID);
			}
			else
			{
				Local_enumErrStatus = DIO_enumLevelErr;
			}
			break;
		case DIO_u8PORTC:
			if(Copy_u8Level == DIO_u8High)
			{
				SET_BIT(PORTC,Local_u8PINID);
			}
			else if(Copy_u8Level == DIO_u8LOW)
			{
				CLR_BIT(PORTC,Local_u8PINID);
			}
			else
			{
				Local_enumErrStatus = DIO_enumLevelErr;
			}
			break;
		case DIO_u8PORTD:
			if(Copy_u8Level == DIO_u8High)
			{
				SET_BIT(PORTD,Local_u8PINID);
			}
			else if(Copy_u8Level == DIO_u8LOW)
			{
				CLR_BIT(PORTD,Local_u8PINID);
			}
			else
			{
				Local_enumErrStatus = DIO_enumLevelErr;
			}
			break;
		default :
			Local_enumErrStatus = DIO_enumChannelErr;
			break;
	}
	return Local_enumErrStatus;
}

DIO_enumErrStatus DIO_enum_ReadChannel (u8 Copy_u8ChannelId, pu8 Add_pu8channelLevel)
{
	u8 Local_u8PINID = Copy_u8ChannelId%8;
	u8 Local_u8PORTID = Copy_u8ChannelId/8;
	DIO_enumErrStatus Local_enumErrStatus = DIO_enumOK;
	if(Add_pu8channelLevel != NULL)
	{
		switch(Local_u8PORTID)
		{
			case DIO_u8PORTA:
					*Add_pu8channelLevel = GET_BIT(PINA,Local_u8PINID);
				break;
			case DIO_u8PORTB:
					*Add_pu8channelLevel = GET_BIT(PINB,Local_u8PINID);
				break;
			case DIO_u8PORTC:
					*Add_pu8channelLevel = GET_BIT(PINC,Local_u8PINID);
				break;
			case DIO_u8PORTD:
					*Add_pu8channelLevel = GET_BIT(PIND,Local_u8PINID);
				break;
			default :
				Local_enumErrStatus = DIO_enumChannelErr;
				break;
		}
	}
	else
	{
		Local_enumErrStatus = DIO_enumNULLptrErr;
	}
	return Local_enumErrStatus;
}
DIO_enumErrStatus DIO_enum_FlipChannel(u8 Copy_u8ChannelId)
{
	u8 Local_u8PINID = Copy_u8ChannelId%8;
	u8 Local_u8PORTID = Copy_u8ChannelId/8;
	DIO_enumErrStatus Local_enumErrStatus = DIO_enumOK;
		switch(Local_u8PORTID)
		{
			case DIO_u8PORTA:
					TGL_BIT(PORTA,Local_u8PINID);
				break;
			case DIO_u8PORTB:
					TGL_BIT(PORTB,Local_u8PINID);
				break;
			case DIO_u8PORTC:
					TGL_BIT(PORTC,Local_u8PINID);
				break;
			case DIO_u8PORTD:
					TGL_BIT(PORTD,Local_u8PINID);
				break;
			default :
				Local_enumErrStatus = DIO_enumChannelErr;
				break;
		}

	return Local_enumErrStatus;	
}
DIO_enumErrStatus DIO_enum_WritePort(u8 Copy_u8PORTId, u8 Copy_u8PORTVal)
{
		DIO_enumErrStatus Local_enumErrStatus = DIO_enumOK;
		switch(Copy_u8PORTId)
		{
			case DIO_u8PORTA:
					PORTA = Copy_u8PORTVal;
				break;
			case DIO_u8PORTB:
					PORTB = Copy_u8PORTVal;
				break;
			case DIO_u8PORTC:
					PORTC = Copy_u8PORTVal;
				break;
			case DIO_u8PORTD:
					PORTD = Copy_u8PORTVal;
				break;
			default :
				Local_enumErrStatus = DIO_enumChannelErr;
				break;
		}
		return Local_enumErrStatus;	
}
DIO_enumErrStatus DIO_enum_ReadPort (u8 Copy_u8PORTId, pu8 Add_pu8PORTVal)
{
		DIO_enumErrStatus Local_enumErrStatus = DIO_enumOK;
		switch(Copy_u8PORTId)
		{
			case DIO_u8PORTA:
					*Add_pu8PORTVal = PINA;
				break;
			case DIO_u8PORTB:
					*Add_pu8PORTVal = PINB;
				break;
			case DIO_u8PORTC:
					*Add_pu8PORTVal = PINC;
				break;
			case DIO_u8PORTD:
					*Add_pu8PORTVal = PIND;
				break;
			default :
				Local_enumErrStatus = DIO_enumChannelErr;
				break;
		}
		return Local_enumErrStatus;		
}
