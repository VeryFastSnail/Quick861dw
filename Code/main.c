
#include <avr/io.h>
#include "global.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Libs/LCD/LCD.h"
#include "Libs/Air/Air.h"
#include "Libs/Buzzer/Buzzer.h"
#include "Libs/Buttons/Buttons.h"
#include "Libs/Motor/Motor.h"


int temp=100;
int tempr = 0;
int main()
{
	INIT();
	
	while (1)
	{
		debounce();
		
		/*if(buttonDown(BTN_TMP_DOWN)){
			if(temp > 100 || temp < 500){
				temp -= 1;
				LCDdisplayTemp(temp);
				BuzzerBeep(20);	
			}
		}
		if(buttonDown(BTN_TMP_UP)){
			if(temp > 100 || temp < 500){
				temp += 1;
				LCDdisplayTemp(temp);
				BuzzerBeep(20);
			}
		}
		
		*/
		
		
		if(buttonDown(BTN_AIR_UP)){
			increaseAirSpeed(1);
		}
		if(buttonDown(BTN_AIR_DOWN)){
			decreaseAirSpeed(1);
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
