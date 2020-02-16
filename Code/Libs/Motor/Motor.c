#include "../../global.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Motor.h"
#include "../Temperature/Temperature.h"


double duty = 50;

void MotorInit(){
	sbi(MOTOR_PWM_P, MOTOR_PWM);
	
	//set PWM
	
	TCCR0 |= (1 << WGM01) | (1 << WGM00) | (1 << COM01);
	
	TIMSK |= (1 << TOIE0);
	
	OCR0 = (duty/100)*255;
	
	sei();
	
	TCCR0 |= (1 << CS00);
	
	
	//set ADC
	//ADMUX &= ~(1 << REFS1) | (1 << REFS0);
	
}

void setDutyCycle(double percent){
	duty = percent;
}

ISR(TIMER0_OVF_vect)
{
	OCR0 = (duty/100)*255;
}


int readMotorEncoder(){
	
}

void rampUpMotor(){
	
}

void rampDownMotor(){
	
}

void stopMotor(){
	
}

void enableADC(){
	ADCSRA |= (1 << ADEN);
}

void disableADC(){
	ADCSRA &= ~(1 << ADEN);
}
