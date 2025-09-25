/*
 * exercise4.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise4.h"
#include "exercise3.h" // use update7SEG()
#include "exercise2.h" // use exercise2_init()

#define TIMER_7SEG 3
#define TIME_7SEG 250

#define TIMER_DOT 4
#define TIME_DOT 1000

#define TIMER_LED_BLINKY 1
#define TIME_LED_BLINKY 1000

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void exercise4_init()
{
	exercise2_init();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_DOT, TIME_DOT);
	setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
}

void exercise4_run()
{
	if (isFlag(TIMER_7SEG))
	{
		update7SEG(index_led);
		++index_led;
		if (index_led >= 4)
		{
			index_led = 0;
		}
		setTimer(TIMER_7SEG, TIME_7SEG);
	}

	if (isFlag(TIMER_DOT))
	{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(TIMER_DOT, TIME_DOT);
	}

	if (isFlag(TIMER_LED_BLINKY))
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
	}
}
