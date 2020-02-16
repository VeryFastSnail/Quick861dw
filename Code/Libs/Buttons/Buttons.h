

#ifndef BUTTONS_H
#define BUTTONS_H


//Control buttons
#define BTN_AIR_UP					PC4
#define BTN_AIR_DOWN				PC3
#define BTN_TMP_UP					PC5
#define BTN_TMP_DOWN				PC6

//Presets buttons

#define BTN_PST_1					PC0
#define BTN_PST_2					PC1
#define BTN_PST_3					PC2


//config

#define BTN_DEBOUNCE				30
#define BTN_PIN						PINC

#define BTN_LNG_PRESS				2000

void	ButtonsInit();
int		IsButtonPressed(uint8_t btn);

#endif