#include "../../global.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Buttons.h"


volatile uint8_t buttons_down;

void ButtonsInit(){
	
	//Init buttons : set as input and enable pull up resistors to make debounce bit more easier.
	
	//Set internal pull up resistor for control keys 
	
	sbi(PORTC, BTN_AIR_UP);
	sbi(PORTC, BTN_AIR_DOWN);
	sbi(PORTC, BTN_TMP_UP);
	sbi(PORTC, BTN_TMP_DOWN);
	
	//Set internal pull up resistor for presets keys 
	sbi(PORTC, BTN_PST_3);
	sbi(PORTC, BTN_PST_2);
	sbi(PORTC, BTN_PST_1);
}


void debounce(){
	
	uint8_t countHigh = 0xff, countLow = 0xff;
	static uint8_t buttonsState = 0;
	
	uint8_t state_changed = ~BTN_PIN ^ buttonsState;
	
	state_changed &= countLow & countHigh;// Change button_state for the buttons who’s counters rolled over
	buttonsState ^= state_changed;
	
	buttons_down |= buttonsState & state_changed;
}

uint8_t buttonDown(uint8_t mask){
	mask &= buttons_down;
	buttons_down ^= mask;
	return mask;
}