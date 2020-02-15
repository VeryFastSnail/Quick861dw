#include "../../global.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Buttons.h"



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

int IsButtonPressed(uint8_t btn){
	if (bit_is_clear(BTN_PIN, btn)){
		delay(BTN_DEBOUNCE);
		return 1;
	}
	return 0;
}
