#include "../../global.h"
#include "avr/io.h"
#include <util/delay.h>
#include "Buzzer.h"

void BuzzerInit(void){
	sbi(DDRA, BUZZ);
}

void BuzzerBeep(int timeMs) {
	sbi(PORTA, BUZZ);
		while(timeMs--) {
			delay(1);
		}
	cbi(PORTA, BUZZ);
}
