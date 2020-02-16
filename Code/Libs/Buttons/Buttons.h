

#ifndef BUTTONS_H
#define BUTTONS_H


//Control buttons
#define BTN_AIR_UP					(1 << PC4)
#define BTN_AIR_DOWN				(1 << PC3)
#define BTN_TMP_UP					(1 << PC5)
#define BTN_TMP_DOWN				(1 << PC6)

//Presets buttons

#define BTN_PST_1					(1 << PC0)
#define BTN_PST_2					(1 << PC1)
#define BTN_PST_3					(1 << PC2)


//config

#define BTN_DEBOUNCE				30
#define BTN_PIN						PINC

#define BTN_LNG_PRESS				2000


#define VC_DEC_OR_SET(high, low, mask)          \
low = ~(low & mask);							\
high = low ^ (high & mask)

void debounce();
void ButtonsInit();
uint8_t buttonDown(uint8_t mask);

#endif