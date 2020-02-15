#ifndef BUZZER_H
#define BUZZER_H


#define BUZZ				PA7
#define BUZZ_TIME_LIM		2000

void BuzzerInit(void);
void BuzzerBeep(int timeMs);


#endif