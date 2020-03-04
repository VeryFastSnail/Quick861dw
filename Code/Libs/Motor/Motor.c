#include "../../global.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Motor.h"
#include "../Temperature/Temperature.h"


double	dutyCycle		= 50;
double	newDutyCycle	= -1;
int		speed			= 0;

void MotorInit(){
	//sbi(MOTOR_PWM_P, MOTOR_PWM);
	
	//set PWM
	/*TCCR1A = (1 << COM1B1) | (1 << COM1B0) | (1 << COM1B1) | (1 << WGM10) | (1 << WGM11);
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
	OCR1BH = 512;
	
	sei();
	*/
	//set ADC
	//ADMUX &= ~(1 << REFS1) | (1 << REFS0);
	
}

void setDutyCycle(double percent){
	//duty = percent;
}

void setMotorSpeedByAir(int airSpeed){
	dutyCycle = getMotorSpeedProportion(airSpeed);
}

int getMotorSpeedProportion(int airSpeed){
	if(airSpeed <=0 || airSpeed >= 100){
		return 0;
	}
	return (airSpeed*1023)/100;
}

ISR(TIMER0_OVF_vect)
{
	//OCR0 = (duty/100)*255;
}


int readMotorEncoder(){
	
}

void rampUpMotor(int airSpeed){
	newDutyCycle = getMotorSpeedProportion(airSpeed);
}

void rampDownMotor(){
	newDutyCycle = 0;
}

void stopMotor(){
	dutyCycle = 0;
}