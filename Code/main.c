
#include <avr/io.h>
#include "global.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Libs/LCD/LCD.h"
#include "Libs/Buzzer/Buzzer.h"
#include "Libs/Buttons/Buttons.h"
	
int temp=100;

int main()
{
	INIT();
	
	sei();
	
	while (1)
	{
		
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
	
	//Timmer for button polling
	
	TCCR0 |= (1 << WGM01) | (1 << CS02) | (1 << CS00);
	OCR0 |= 20;
	
	
	
}

ISR(TIMER0_COMP_vect){
	
}