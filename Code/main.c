
#include <avr/io.h>
#include "global.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Libs/LCD/LCD.h"
#include "Libs/Air/Air.h"
#include "Libs/Buzzer/Buzzer.h"
#include "Libs/Buttons/Buttons.h"
#include "Libs/Motor/Motor.h"


int temp=20;
int tempr = 0;

int sleepMode = 1;
int wandPosition = 1;

int main()
{
	INIT();
	
	while (1)
	{
		//@todo debouce buttons on timer0
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
		if(buttonDown(BTN_TMP_UP)){
			increaseTemperature(1);
		}
		if(buttonDown(BTN_TMP_DOWN)){
			decreaseTemperature(1);
		}
		
		sbi(DDRD, PD4);
		
		TCCR1A |= (1 << COM1B1) | (1 << WGM10) | (1 << WGM12);
		TCCR1B |= (1 << CS10);
		OCR1B = 256;                     
		TIMSK |= OCIE1B;
		
		//set interrupt to input
		//sbi(DDRD, PD3);
		MCUCR	|= (1 << ISC10);
		GIFR	|= (1 << INTF1);
		GICR	|= (1 << INT1);
		sei();
		
	}
	return 0;
}

ISR(ADC_vect)
{
	temp=ADC/10;	
}

ISR(INT1_vect)
{
	if(bit_is_clear(PIND, PD3)){
		wandPosition = 1;
		LCDSleep();
	} else {
		wandPosition = 0;
		LCDWakeUp();
	}
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
	
	setupADC();
	startADC();
	
}

void setupADC(){
	//DDRA |= (1 << PA0);
	ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}
void startADC(){
	ADCSRA |= (1 << ADSC);
}
void stopADC(){
	ADCSRA &= ~(1 << ADSC);
}

void setupPWM(){
	DDRD		|= (1 << PD4);
	TCCR1A		|= (1 << COM1B1) | (1 << WGM12) | (1 << WGM10);
	TIMSK		|= (1 << OCIE1B);
	
	TCCR1B		|= (1 << CS10);
}