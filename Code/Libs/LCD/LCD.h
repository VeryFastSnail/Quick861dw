

#ifndef LCD_H
#define LCD_H

#define  LCD_ComMode    0x52
#define  LCD_RCosc      0x30
#define  LCD_LCD_on     0x06
#define  LCD_LCD_off    0x04
#define  LCD_Sys_en     0x02
#define  LCD_CTRl_cmd   0x80
#define  LCD_Data_cmd   0xa0

#define LCD_PORT		PORTB
#define LCD_CS			PB3
#define LCD_WR			PB2
#define LCD_DT			PB1

void LCDdisplayDigit(int digit, int address);
void LCDSendBit(uchar sdata,uchar cnt);
void LCDSendCmd(uchar command);
void LCDWrite(uchar addr,uchar sdata);
void LCDAllSegementsOff(uchar num);
void LCDAllSegementsOn(uchar num);
void LCDInit(void);
void LCDSetPins(void);
void LCDdisplayTemp(int temp);
void LCDdisplayAir(int speed);
void LCDdrawSleepIndicators();
void LCDdisplayTempType(int type);
int countDigits(int number);
void LCDWakeUp();
void LCDSleep();
#endif

