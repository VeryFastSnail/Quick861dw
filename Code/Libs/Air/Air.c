#include "../../global.h"
#include "../LCD/LCD.h"
#include "../Buzzer/Buzzer.h"
#include "Air.h"

int airSpeed = 5;

int getAirSpeed(){
	return airSpeed;
}

void setAirSpeed(int speed) {
	airSpeed = speed;
}

void increaseAirSpeed(int number){
	if(getAirSpeed()+number <= AIR_CAP_HIGH){
		airSpeed += number;
		LCDdisplayAir(airSpeed);
		BuzzerBeep(20);
	}
}
void decreaseAirSpeed(int number){
	if(getAirSpeed()-number >= AIR_CAP_LOW){
		airSpeed -= number;
		LCDdisplayAir(airSpeed);
		BuzzerBeep(20);
	}
}