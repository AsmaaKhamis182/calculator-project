#ifndef DIO_INT_H_
#define DIO_INT_H_
typedef enum
{
	DIO_enumOK,
	DIO_enumChannelErr,
	DIO_enumLevelErr,
	DIO_enumDirErr,
	DIO_enumNULLptrErr,
	DIO_enumPORTrangeErr
}DIO_enumErrStatus;

/*DIO LEVELS*/
#define	DIO_u8LOW				0
#define DIO_u8High				1
/*PORTA*/
#define DIO_u8PORTAPIN0			0
#define DIO_u8PORTAPIN1			1
#define DIO_u8PORTAPIN2			2
#define DIO_u8PORTAPIN3			3
#define DIO_u8PORTAPIN4			4
#define DIO_u8PORTAPIN5			5
#define DIO_u8PORTAPIN6			6
#define DIO_u8PORTAPIN7			7
/*PORTB*/
#define DIO_u8PORTBPIN0			8
#define DIO_u8PORTBPIN1			9
#define DIO_u8PORTBPIN2			10
#define DIO_u8PORTBPIN3			11
#define DIO_u8PORTBPIN4			12
#define DIO_u8PORTBPIN5			13
#define DIO_u8PORTBPIN6			14
#define DIO_u8PORTBPIN7			15
/*PORTC*/
#define DIO_u8PORTCPIN0			16
#define DIO_u8PORTCPIN1			17
#define DIO_u8PORTCPIN2			18
#define DIO_u8PORTCPIN3			19
#define DIO_u8PORTCPIN4			20
#define DIO_u8PORTCPIN5			21
#define DIO_u8PORTCPIN6			22
#define DIO_u8PORTCPIN7			23
/*PORTD*/
#define DIO_u8PORTDPIN0			24
#define DIO_u8PORTDPIN1			25
#define DIO_u8PORTDPIN2			26
#define DIO_u8PORTDPIN3			27
#define DIO_u8PORTDPIN4			28
#define DIO_u8PORTDPIN5			29
#define DIO_u8PORTDPIN6			30
#define DIO_u8PORTDPIN7			31

/*PORTS CHOICE*/
#define DIO_u8PORTA				0
#define DIO_u8PORTB				1
#define DIO_u8PORTC				2
#define DIO_u8PORTD				3

DIO_enumErrStatus DIO_enum_WriteChannel(u8 Copy_u8ChannelId, u8 Copy_u8Level);
DIO_enumErrStatus DIO_enum_ReadChannel (u8 Copy_u8ChannelId, pu8 Add_pu8channelLevel);
DIO_enumErrStatus DIO_enum_FlipChannel(u8 Copy_u8ChannelId);
DIO_enumErrStatus DIO_enum_WritePort(u8 Copy_u8PORTId, u8 Copy_u8PORTVal);
DIO_enumErrStatus DIO_enum_ReadPort (u8 Copy_u8PORTId, pu8 Add_pu8PORTVal);
#endif
