#ifndef PORT_H_
#define PORT_H_
/*PORTA*/
#define PORT_u8PORTAPIN0			0
#define PORT_u8PORTAPIN1			1
#define PORT_u8PORTAPIN2			2
#define PORT_u8PORTAPIN3			3
#define PORT_u8PORTAPIN4			4
#define PORT_u8PORTAPIN5			5
#define PORT_u8PORTAPIN6			6
#define PORT_u8PORTAPIN7			7
/*PORTB*/
#define PORT_u8PORTBPIN0			8
#define PORT_u8PORTBPIN1			9
#define PORT_u8PORTBPIN2			10
#define PORT_u8PORTBPIN3			11
#define PORT_u8PORTBPIN4			12
#define PORT_u8PORTBPIN5			13
#define PORT_u8PORTBPIN6			14
#define PORT_u8PORTBPIN7			15
/*PORTC*/
#define PORT_u8PORTCPIN0			16
#define PORT_u8PORTCPIN1			17
#define PORT_u8PORTCPIN2			18
#define PORT_u8PORTCPIN3			19
#define PORT_u8PORTCPIN4			20
#define PORT_u8PORTCPIN5			21
#define PORT_u8PORTCPIN6			22
#define PORT_u8PORTCPIN7			23
/*PORTD*/
#define PORT_u8PORTDPIN0			24
#define PORT_u8PORTDPIN1			25
#define PORT_u8PORTDPIN2			26
#define PORT_u8PORTDPIN3			27
#define PORT_u8PORTDPIN4			28
#define PORT_u8PORTDPIN5			29
#define PORT_u8PORTDPIN6			30
#define PORT_u8PORTDPIN7			31
        
/*PORTS Direction*/
#define PORT_u8PINDIR_OUTPUT		1
#define PORT_u8PINDIR_INPUT			0
/*PORTS mode*/
#define PORT_u8PINMODE_OUTPUT_LOW		0
#define PORT_u8PINMODE_OUTPUT_HIGH		1
#define PORT_u8PINMODE_INPUT_FLOATING	2
#define PORT_u8PINMODE_INPUUT_PULLUP	3	

/*PORTS choice*/
#define PORT_u8PORTA				0
#define PORT_u8PORTB				1
#define PORT_u8PORTC				2
#define PORT_u8PORTD				3
typedef enum
{
	PORT_enumOK,
	PORT_enumPINerr,
	PORT_enumDIRerr
}PORT_enumErrStatus;


void PORT_voidInit(void);
PORT_enumErrStatus PORT_enumSET_PINDirection(u8 Copy_u8PINNum, u8 Copy_u8PINDirection);
PORT_enumErrStatus PORT_enumSET_PINMODE(u8 Copy_u8PINNum, u8 Copy_u8PINMODE);




#endif
