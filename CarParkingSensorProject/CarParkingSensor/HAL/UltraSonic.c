#include "./UltraSonic.h"
#include "../MCAL/icu.h"
#include "util/delay.h"
#include "../MCAL/GPIO.h"

static volatile uint8 g_edgeCount = 0;
static volatile uint16 g_timeHigh = 0;

void Ultrasonic_init(void) {
	//Initialize ICU with the required settings
	ICU_ConfigType ICU_Config = { F_CPU_8, RISING };
	ICU_init(&ICU_Config);

	//Setup the callBakc_Function
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(TRIGGER_PORT, TRIGGER_PIN, PIN_OUTPUT);
}

void Ultrasonic_edgeProcessing(void) {
	g_edgeCount++;
	if (g_edgeCount == 1) {
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	} else if (g_edgeCount == 2) {
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RISING);
	}
	else{
		g_edgeCount = 0;
	}
}

void Ultrasonic_Trigger(void) {
	// trigger pulse
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_HIGH);  // set pin high
	_delay_us(TRIGGER_PULSE_WIDTH); // wait microseconds
	GPIO_writePin(TRIGGER_PORT, TRIGGER_PIN, LOGIC_LOW);
	// clear pin
}

uint16 Ultrasonic_readDistance(void) {
	uint16 distance = 0;

	Ultrasonic_Trigger();

	while (g_edgeCount != NUM_EDGES_DETECT);

	distance =0.017 * g_timeHigh;

	return distance;
}

