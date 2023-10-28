#ifndef BIT_UTILS_H
#define BIT_UTILS_H

#define SET_BIT(Reg,Bit)         	Reg|=(1<<Bit)
#define CLR_BIT(Reg,Bit)         	Reg&=~(1<<Bit)
#define GET_BIT(Reg,Bit)         	((Reg>>Bit)&(1))
#define RSHFT_REG(Reg,No)        	Reg=(Reg>>No)
#define LSHFT_REG(Reg,No)        	Reg=(Reg<<No)
#define CRSHFT_REG(Reg,No)       	Reg=((Reg<<No)|(Reg>>(sizeof((Reg)*8)-(No))))
#define CLSHFT_REG(Reg,No)       	Reg=((Reg>>No)|(Reg<<(sizeof((Reg)*8)-(No))))
#define ASSIGN_REG(Reg,Value)       Reg=Value
#define SET_REG(Reg)             	Reg=~(0)
#define CLR_REG(Reg)             	Reg=(0)
#define TGL_BIT(Reg,Bit)         	Reg^=(1<<Bit)
#define TGL_REG(Reg,Bit)         	Reg^=~(0)
#define SET_H_NIB(Reg)           	Reg|=(0xF0)
#define SET_L_NIB(Reg)           	Reg|=(0x0F)
#define CLR_H_NIB(Reg)           	Reg&=(0x0F)
#define CLR_L_NIB(Reg)           	Reg&=(0xF0)
#define GET_H_NIB(Reg)              (Reg&(0xF0))>>4
#define GET_L_NIB(Reg)           	(Reg&(0x0F))
#define ASSIGN_H_NIB(Reg_Value)     Reg=(Reg & 0x0F)|(Value<<4)    
#define ASSIGN_L_NIB(Reg_Value)     Reg =(Reg & 0xF0) | (Value)      
#define TGL_H_NIB(Reg)              Reg^=(0xF0)      
#define TGL_L_NIB(Reg)              Reg^=(0x0F)      
#define SWAP_NIB(Reg)               Reg=((Reg<<4)|(Reg>>4))
#define TGLWITHOUTASSIGN_BIT(Reg,Bit)         	Reg^(1<<Bit)


#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)			CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)		0b##B7##B6##B5##B4##B3##B2##B1##B0

#endif      