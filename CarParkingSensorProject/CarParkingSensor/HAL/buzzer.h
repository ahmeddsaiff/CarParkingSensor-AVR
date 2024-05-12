#ifndef HAL_BUZZER_H_
#define HAL_BUZZER_H_

#include "avr/io.h"
#include <avr/interrupt.h>
#include "../MCAL/GPIO.h"
#include "../CommonHeader-UsedFiles/common_macros.h"
#include "../CommonHeader-UsedFiles/std_types.h"

#define BUZZER_PIN_ID PIN0_ID
#define BUZZER_PORT_ID PORTC_ID
#define BUZZER_PORT PORTC

uint8 g_ticks ;

void Buzzer_init(void);
void Timer0_Init_Normal_Mode(void);
void Timer0_DeInit(void);
void Timer0_Clock(void);



#endif /* HAL_BUZZER_H_ */
