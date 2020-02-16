#include "../../global.h"
#include <avr/io.h>
#include "LCD.h"
#include "../Air/Air.h"
#include <math.h>


const char numbers[10] = {0xFA, 0x0A, 0xBC, 0x9E, 0x4E, 0xD6, 0xF6, 0x8A, 0xFE, 0xDE};
	
#define TempType		1;

int countDigits(int number){
	return floor(log10(abs(number))) + 1;
}


void LCDSendBit(uchar sdata,uchar cnt)
{
	uchar i;
	for(i=0;i<cnt;i++)
	{
		cbi(PORTB, LCD_WR);
		if(sdata&0x80){
			sbi(PORTB, LCD_DT);
		}
		else {
			cbi(PORTB, LCD_DT);
		}
		sbi(PORTB, LCD_WR);
		sdata<<=1;
	}
}

void LCDSendCmd(uchar command)
{
	cbi(PORTB, LCD_CS);
	LCDSendBit(0x80,4);
	LCDSendBit(command,8);
	sbi(PORTB, LCD_CS);
}

void LCDWrite(uchar addr,uchar sdata)
{
	addr<<=2;
	cbi(PORTB, LCD_CS);
	LCDSendBit(0xa0,3);
	LCDSendBit(addr,6);
	LCDSendBit(sdata,8); // edited from 8 to 4
	sbi(PORTB, LCD_CS);
}

void LCDAllSegementsOff(uchar num)
{
	uchar i;
	uchar addr=0;
	for(i=0;i<num;i++)
	{
		LCDWrite(addr,0x00);
		addr+=2;
	}
}

void LCDAllSegementsOn(uchar num)
{
	uchar i;
	uchar addr=0;
	for(i=0;i<num;i++)
	{
		LCDWrite(addr,0xff);
		addr+=2;
	}
}

void LCDSetPins(void){
	sbi(DDRB, LCD_WR);
	sbi(DDRB, LCD_CS);
	sbi(DDRB, LCD_DT);
}

void LCDInit(void)
{
	LCDSendCmd(LCD_Sys_en);
	LCDSendCmd(LCD_RCosc);
	LCDSendCmd(LCD_ComMode);
	LCDSendCmd(LCD_LCD_on);
}
void LCDdisplayDigit(int digit, int address){
	if(!(digit > 9 || digit < 0) && !(address < 0 || address > 16)) {
		LCDWrite(address, numbers[digit]);
	}
}

void LCDdisplayTemp(int temp){
			
	//@todo implement individual digit check if changed check
	
	if(!(temp < 100 || temp > 500)){
		
		int digits[3];
		
		for (int i = 3; i >= 0; i--) {
			digits[i] = temp % 10;
			temp /= 10;
		}
		
		LCDWrite(2, numbers[digits[1]]);
		LCDWrite(4, numbers[digits[2]]);
		LCDWrite(6, numbers[digits[3]]);
	}
}

void LCDdisplayAir(int speed){
	
		int qty = countDigits(speed);
		int digits[3] = {0,0,0};
		
		for (int i = 0; i <= qty; i++) {
			digits[i] = speed % 10;
			speed /= 10;
		}
		
			LCDWrite(9, numbers[digits[2]]);
			LCDWrite(11, numbers[digits[1]]);
			LCDWrite(13, numbers[digits[0]]);
	
}


void LCDdrawSleepIndicators(){
	
	LCDWrite(2, 0x04);
	LCDWrite(4, 0x04);
	LCDWrite(6, 0x04);
	
	LCDWrite(9, 0x04);
	LCDWrite(11, 0x04);
	LCDWrite(13, 0x04);
	
}

void LCDdisplayTempType(int type){
	if(type == 1) {
		LCDWrite(7, 0x02);	
	} else {
		LCDWrite(11, 0x01);
	}
}


void LCDSleep(){
	LCDAllSegementsOff(8);
	LCDdrawSleepIndicators();
}