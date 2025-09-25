/*
 * exercise3.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise3.h"
#include "exercise2.h" // use exercise2_init()
#include "exercise1.h" // use display7SEG() and enable_seg()

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1

#define TIMER_7SEG 3
#define TIME_7SEG 20

#define TIMER_DOT 4
#define TIME_DOT 1000

#define TIMER_LED_BLINKY 1
#define TIME_LED_BLINKY 1000

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};

void exercise3_init()
{
	exercise2_init();
	setTimer(TIMER_7SEG, TIME_7SEG);
	setTimer(TIMER_DOT, TIME_DOT);
	setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
}

void exercise3_run()
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

void update7SEG(int idx)
{
	switch (idx) {
		case 0:
			display7SEG(led_buffer[0]);
			enable_seg(0);
			break;
		case 1:
			display7SEG(led_buffer[1]);
			enable_seg(1);
			break;
		case 2:
			display7SEG(led_buffer[2]);
			enable_seg(2);
			break;
		case 3:
			display7SEG(led_buffer[3]);
			enable_seg(3);
			break;
		default:
			break;
	}
}
