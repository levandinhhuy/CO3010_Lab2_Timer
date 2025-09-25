/*
 * exercise1.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise1.h"

#define LED_ON 0
#define LED_OFF 1

#define ENABLE_SEG 0
#define DISABLE_SEG 1

#define TIMER_7SEG 0
#define TIME_7SEG 500

#define TIMER_LED_BLINKY 1
#define TIME_LED_BLINKY 1000

typedef enum
{
	INIT,
	LED1,
	LED2
} Exercise1_State;

Exercise1_State ex1_state = INIT;

void exercise1_init()
{
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	HAL_GPIO_TogglePin(EN0_GPIO_Port, EN0_Pin);
	HAL_GPIO_TogglePin(EN1_GPIO_Port, EN1_Pin);
	HAL_GPIO_TogglePin(SEG0_GPIO_Port, SEG0_Pin);
	HAL_GPIO_TogglePin(SEG1_GPIO_Port, SEG1_Pin);
	HAL_GPIO_TogglePin(SEG2_GPIO_Port, SEG2_Pin);
	HAL_GPIO_TogglePin(SEG3_GPIO_Port, SEG3_Pin);
	HAL_GPIO_TogglePin(SEG4_GPIO_Port, SEG4_Pin);
	HAL_GPIO_TogglePin(SEG5_GPIO_Port, SEG5_Pin);
	HAL_GPIO_TogglePin(SEG6_GPIO_Port, SEG6_Pin);
	setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
}

void exercise1_run()
{
	switch (ex1_state) {
		case INIT:
			if (1)
			{
				ex1_state = LED1;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED1:
			display7SEG(1);
			enable_seg(0);
			if (isFlag(TIMER_7SEG))
			{
				ex1_state = LED2;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		case LED2:
			display7SEG(2);
			enable_seg(1);
			if (isFlag(TIMER_7SEG))
			{
				ex1_state = LED1;
				setTimer(TIMER_7SEG, TIME_7SEG);
			}
			break;
		default:
			break;
	}

	if (isFlag(TIMER_LED_BLINKY))
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer(TIMER_LED_BLINKY, TIME_LED_BLINKY);
	}
}

void display7SEG(int num)
{
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_OFF);
			break;
		case 1:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_OFF);
			break;
		case 2:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		case 3:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		case 4:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		case 5:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		case 6:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		case 7:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_OFF);
			break;
		case 8:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		case 9:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_ON);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_ON);
			break;
		default:
			HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, LED_OFF);
			HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, LED_OFF);
			break;
	}
}

void enable_seg(int num)
{
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, DISABLE_SEG);
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, DISABLE_SEG);
			break;
		case 2:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, ENABLE_SEG);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, DISABLE_SEG);
			break;
		case 3:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, DISABLE_SEG);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, ENABLE_SEG);
			break;
		default:
			break;
	}
}
