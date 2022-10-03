#define FSYSCLK  7372800


extern bit BIT_TMP;
extern unsigned char data  TA_REG_TMP,SFRS_TMP,BYTE_TMP;

unsigned char Read_APROM_BYTE(unsigned int code *u16_addr);
void Global_Interrupt(unsigned char u8IntStatus);
void PowerDown_Level(unsigned char u8PDLevel);
