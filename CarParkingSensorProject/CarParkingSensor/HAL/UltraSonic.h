#ifndef HAL_ULTRASONIC_H_
#define HAL_ULTRASONIC_H_

#include "../CommonHeader-UsedFiles/std_types.h"
#include "../MCAL/GPIO.h"
#include "avr/io.h"

#define TRIGGER_PORT PORTB_ID
#define TRIGGER_PULSE_WIDTH 12
#define TRIGGER_PIN PIN5_ID

#define NUM_EDGES_DETECT 2




void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);



#endif /* HAL_ULTRASONIC_H_ */
