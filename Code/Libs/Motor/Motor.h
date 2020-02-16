/*
 * Motor.h
 *
 * Created: 2020-02-16 07:24:45
 *  Author: Rokas
 */ 


#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_PWM				PD4
#define MOTOR_ENCODER			PB0	

#define MOTOR_ENCODER_P			PORTB
#define MOTOR_PWM_P				PORTD



void MotorInit();
void setDutyCycle(double percent);
int readMotorEncoder();
void rampUpMotor();
void rampDownMotor();
void stopMotor();
void enableADC();
void disableADC();


#endif /* MOTOR_H_ */