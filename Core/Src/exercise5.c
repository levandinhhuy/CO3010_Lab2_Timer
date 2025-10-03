/*
 * exercise5.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise5.h"
#include "exercise3.h" // use update7SEG()
#include "exercise2.h" // use exercise2_init()

#define TIMER_7SEG 5
#define TIME_7SEG 250

#define TIMER_DOT 6
#define TIME_DOT 1000

#define TIMER_LED_BLINKY 1
#define TIME_LED_BLINKY 1000

extern int index_led;
extern int led_buffer[4];

int hour = 15, minute = 59, second = 50;

void exercise5_init()
{
	exercise2_init();
	updateClockBuffer();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_DOT, TIME_DOT);
	setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
}

void exercise5_run()
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
		++second;
		if (second >= 60)
		{
			second = 0;
			++minute;
		}
		if (minute >= 60)
		{
			minute = 0;
			++hour;
		}
		if (hour >= 24)
		{
			hour = 0;
		}
		updateClockBuffer();
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		setTimer(TIMER_DOT, TIME_DOT);
	}

	if (isFlag(TIMER_LED_BLINKY))
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
	}
}

void updateClockBuffer()
{
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}
