

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#define TMP_CAP_HIGH			500
#define TMP_CAP_LOW				100

int getTemperature();
void setTemperature(int temperature);
void increaseTemperature(int number);
void decreaseTemperature(int number);

#endif