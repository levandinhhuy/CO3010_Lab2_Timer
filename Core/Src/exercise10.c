/*
 * exercise10.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise10.h"
#include "exercise9.h"

extern const int MAX_LED_MATRIX;
extern int index_led_matrix;
extern uint8_t matrix_buffer[8];

#define TIMER_SCAN_LED 1
#define TIME_SCAN_LED 50

#define TIMER_UPDATE_BUFFER 2
#define TIME_UPDATE_BUFFER 1000

void exercise10_init()
{
	HAL_GPIO_TogglePin(ENM0_GPIO_Port, ENM0_Pin);
	HAL_GPIO_TogglePin(ENM1_GPIO_Port, ENM1_Pin);
	HAL_GPIO_TogglePin(ENM2_GPIO_Port, ENM2_Pin);
	HAL_GPIO_TogglePin(ENM3_GPIO_Port, ENM3_Pin);
	HAL_GPIO_TogglePin(ENM4_GPIO_Port, ENM4_Pin);
	HAL_GPIO_TogglePin(ENM5_GPIO_Port, ENM5_Pin);
	HAL_GPIO_TogglePin(ENM6_GPIO_Port, ENM6_Pin);
	HAL_GPIO_TogglePin(ENM7_GPIO_Port, ENM7_Pin);
	HAL_GPIO_TogglePin(ROW0_GPIO_Port, ROW0_Pin);
	HAL_GPIO_TogglePin(ROW1_GPIO_Port, ROW1_Pin);
	HAL_GPIO_TogglePin(ROW2_GPIO_Port, ROW2_Pin);
	HAL_GPIO_TogglePin(ROW3_GPIO_Port, ROW3_Pin);
	HAL_GPIO_TogglePin(ROW4_GPIO_Port, ROW4_Pin);
	HAL_GPIO_TogglePin(ROW5_GPIO_Port, ROW5_Pin);
	HAL_GPIO_TogglePin(ROW6_GPIO_Port, ROW6_Pin);
	HAL_GPIO_TogglePin(ROW7_GPIO_Port, ROW7_Pin);
	setTimer(TIMER_SCAN_LED, TIME_SCAN_LED);
	setTimer(TIMER_UPDATE_BUFFER, TIME_UPDATE_BUFFER);
}

void exercise10_run()
{
	if (isFlag(TIMER_SCAN_LED))
	{
		updateLEDMatrix(index_led_matrix);
		++index_led_matrix;
		if (index_led_matrix >= 8)
		{
			index_led_matrix = 0;
		}
		setTimer(TIMER_SCAN_LED, TIME_SCAN_LED);
	}

	if (isFlag(TIMER_UPDATE_BUFFER))
	{
		shift_left_matrix();
		setTimer(TIMER_UPDATE_BUFFER, TIME_UPDATE_BUFFER);
	}
}

void shift_left_matrix()
{
	for (int i = 0; i < MAX_LED_MATRIX; ++i)
	{
		matrix_buffer[i] = (matrix_buffer[i] << 1) | (matrix_buffer[i] >> 7);
	}
}
