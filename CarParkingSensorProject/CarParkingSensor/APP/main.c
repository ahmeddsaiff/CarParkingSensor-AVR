#include "./main.h"

int main(void) {
	SREG |= (1 << 7);
	Timer0_Init_Normal_Mode();
	Buzzer_init();
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance=     cm");
	while (1) {
		displayDistance_BuzzerOnOff();
	}
}



