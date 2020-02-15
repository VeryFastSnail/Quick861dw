
#include <avr/io.h>
#include "global.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Libs/LCD/LCD.h"
#include "Libs/Buzzer/Buzzer.h"
#include "Libs/Buttons/Buttons.h"
	
//test var
int temp=100;
	
int main()
{
	INIT();
	
	while (1)
	{
		if(IsButtonPressed(BTN_TMP_UP)){
			temp++;
			LCDdisplayTemp(temp);
			BuzzerBeep(100);
		}
		if(IsButtonPressed(BTN_TMP_DOWN)){
			temp--;
			LCDdisplayTemp(temp);
			BuzzerBeep(100);
		}
		if(IsButtonPressed(BTN_AIR_UP)){
			temp++;
			LCDdisplayAir(temp);
		}
		if(IsButtonPressed(BTN_AIR_DOWN)){
			temp--;
			LCDdisplayAir(temp);
		}
	}
	return 0;
}


void INIT(){
	BuzzerInit();
	ButtonsInit();
	
	
	//LCD stuff
	LCDSetPins();
	sbi(PORTB, LCD_CS);
	sbi(PORTB, LCD_WR);
	sbi(PORTB, LCD_DT);
	
	delay(50);
	LCDInit();
	LCDAllSegementsOff(8);
	LCDdrawSleepIndicators();
}