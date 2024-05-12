#include "./buzzer.h"


/* global variable contain the ticks count of the timer */
uint8 g_tick = 0;

/* Description:
 * For System Clock=8Mhz and timer prescaler is F_CPU/1024.
 * Timer frequency will be around 1Khz, Ttimer = 128us
 */
void Timer0_Init_Normal_Mode(void)
{
	TCNT0 = 0; //Set Timer initial value to 0

	TIMSK |= (1<<TOIE0); // Enable Timer0 Overflow Interrupt

	/* Configure the timer control register
	 * 1. Non PWM mode FOC0=1
	 * 2. Normal Mode WGM01=0 & WGM00=0
	 * 3. Normal Mode COM00=0 & COM01=0
	 */
	TCCR0 = (1<<FOC0);
}

ISR(TIMER0_OVF_vect)
{
	g_tick++;

	if(g_tick == g_ticks)
	{
		PORTC = PORTC ^ (1<<PC0);
		g_tick = 0;
	}
}

void Timer0_DeInit(void){
	TCCR0 &= ~(1<<CS02) & ~(1<<CS00);
	GPIO_writePin(BUZZER_PORT_ID , BUZZER_PIN_ID , LOGIC_LOW);
}

void Timer0_Clock(void){
	//TCNT0 = 0;
	// 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	TCCR0 |= (1<<CS02) | (1<<CS00);
}

void Buzzer_init(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID , BUZZER_PIN_ID , PIN_OUTPUT);
}





