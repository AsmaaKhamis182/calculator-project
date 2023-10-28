#ifndef LCD_H_
#define LCD_H_

#define RS	DIO_u8PORTAPIN3
#define EN	DIO_u8PORTAPIN2

#define D4	DIO_u8PORTBPIN0
#define D5	DIO_u8PORTBPIN1
#define D6	DIO_u8PORTBPIN2
#define D7	DIO_u8PORTBPIN4

#define FunctionSet1_Command		0b00100010
#define FunctionSet2_Command		0b10000000


#define LCD_ROW0		0
#define	LCD_ROW1		1
#define	LCD_ROW2		2
#define	LCD_ROW3		3

#define LCD_Coloumn0	0
#define LCD_Coloumn1	1
#define LCD_Coloumn2	2
#define LCD_Coloumn3	3
#define LCD_Coloumn4	4
#define LCD_Coloumn5	5
#define LCD_Coloumn6	6
#define LCD_Coloumn7	7
#define LCD_Coloumn8	8
#define LCD_Coloumn9	9
#define LCD_Coloumn10	10
#define LCD_Coloumn11	11
#define LCD_Coloumn12	12
#define LCD_Coloumn13	13
#define LCD_Coloumn14	14
#define LCD_Coloumn15	15
#define LCD_Coloumn16	16
#define LCD_Coloumn17	17
#define LCD_Coloumn18	18
#define LCD_Coloumn19	19


#define LCD_CLEAR             0x01 /* replace all characters with ASCII 'space'     */
#define LCD_RETURN_HOME       0x02 /* return cursor to first position on first line */
#define LCD_ENTRY_MODE        0x06 /* shift cursor from left to right on read/write */
#define LCD_DISPLAY_OFF       0x08 /* turn display off                              */
#define LCD_DISPLAY_ON        0x0C /* display on, cursor off, don't blink character */
#define LCD_RESET       	  0x30 /* reset the LCD                                 */
#define LCD_SET_8BITS_2LINES  0x38 /* 8-bit data, 2-line display, 5 x 7 font        */
#define LCD_CURSOR_OFFSET     0x80 /* set cursor position                           */
#define CG_RAM_ADDRESS		  0x40


void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidWriteChar(u8 Copy_u8Character);
void LCD_voidWriteString(pu8 Ptr_u8String);
void LCD_voidWriteNumbers(f32 Copy_f32Number);
void LCD_voidSetCursorToX_y(u8 Copy_u8Row,u8 Copy_u8Coloumn);
void LCD_voidSendDataBus(u8 Copy_u8BUS);
void LCD_voidCreateCustomChar(u8 CharID,u8 *Copy_CustomChar);
#endif
