/*
 * main.h
 *
 *  Created on: Oct 22, 2023
 *      Author: ahmed
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#include "../HAL/UltraSonic.h"
#include "../HAL/lcd.h"
#include "avr/io.h"
#include "../HAL/buzzer.h"

static uint16 distance;

#define displayDistance_BuzzerOnOff(){\
	distance = Ultrasonic_readDistance();\
	LCD_moveCursor(0, 10);\
	LCD_intgerToString(distance);\
	if (distance < 100) {\
		LCD_displayCharacter(' ');\
	}\
	if (distance < 50 && distance >= 40) {\
		LCD_clearRow(2);\
		Timer0_Clock();\
		g_ticks = 30;\
	} else if (distance < 40 && distance >= 30) {\
		LCD_clearRow(2);\
		Timer0_Clock();\
		g_ticks = 25;\
	} else if (distance < 30 && distance >= 20) {\
		LCD_clearRow(2);\
		Timer0_Clock();\
		g_ticks = 15;\
	} else if (distance < 20 && distance >= 15) {\
		LCD_clearRow(2);\
		Timer0_Clock();\
		g_ticks = 10;\
	} else if (distance < 15 && distance >= 10) {\
		Timer0_Clock();\
		g_ticks = 9;\
		LCD_moveCursor(2, 3);\
		LCD_displayString("SlowDown!!");\
	} else if (distance < 10 && distance >= 5) {\
		Timer0_Clock();\
		g_ticks = 5;\
		LCD_moveCursor(2, 3);\
		LCD_displayString("SlowDown!!");\
	} else if (distance < 5) {\
		Timer0_Clock();\
		g_ticks = 1;\
		LCD_moveCursor(2, 3);\
		LCD_displayString("STOOPPP!!!");\
	} else {\
		Timer0_DeInit();\
	}\
}


#endif /* APP_MAIN_H_ */
