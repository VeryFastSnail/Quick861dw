#include "../../global.h"
#include "../LCD/LCD.h"
#include "../Buzzer/Buzzer.h"
#include "Temperature.h"

int temperature = 110;

int getTemperature(){
	return temperature;
}

void setTemperature(int temp) {
	temperature = temp;
}

void increaseTemperature(int number){
	if(getTemperature()+number <= TMP_CAP_HIGH){
		temperature += number;
		LCDdisplayTemp(temperature);
		BuzzerBeep(20);
	}
}
void decreaseTemperature(int number){
	if(getTemperature()-number >= TMP_CAP_LOW){
		temperature -= number;
		LCDdisplayTemp(temperature);
		BuzzerBeep(20);
	}
}