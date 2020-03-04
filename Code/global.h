
#ifndef GLOBAL_H
#define GLOBAL_H


#define F_CPU 1000000



//macros

#define sbi(x, y)	(x |= (1 << y))
#define cbi(x, y)	(x &= ~(1 <<y ))
#define uchar		unsigned char
#define uint		unsigned int
#define delay(x)	(_delay_ms(x))
#define bit_is_clear(sfr,bit) \
(!(_SFR_BYTE(sfr) & _BV(bit)))


//config

#define BUTTON_PRESS_BEEP_DURATION				20
#define EEPROM_SAVE_PERIOD_SEC					10
						

#endif 
