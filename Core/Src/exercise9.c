/*
 * exercise9.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise9.h"

#define TIMER_MATRIX 6
#define TIME_MATRIX 100

#define ENABLE_LED RESET
#define UNABLE_LED SET

#define ROW0_ON HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET)
#define ROW1_ON HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET)
#define ROW2_ON HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET)
#define ROW3_ON HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET)
#define ROW4_ON HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET)
#define ROW5_ON HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET)
#define ROW6_ON HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET)
#define ROW7_ON HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET)

#define ROW0_OFF HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET)
#define ROW1_OFF HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET)
#define ROW2_OFF HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET)
#define ROW3_OFF HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET)
#define ROW4_OFF HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET)
#define ROW5_OFF HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET)
#define ROW6_OFF HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET)
#define ROW7_OFF HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET)

GPIO_TypeDef *PORT_OF_ROW[8] = {
		ROW0_GPIO_Port,
		ROW1_GPIO_Port,
		ROW2_GPIO_Port,
		ROW3_GPIO_Port,
		ROW4_GPIO_Port,
		ROW5_GPIO_Port,
		ROW6_GPIO_Port,
		ROW7_GPIO_Port
};

uint16_t PIN_OF_ROW[8] = {
		ROW0_Pin,
		ROW1_Pin,
		ROW2_Pin,
		ROW3_Pin,
		ROW4_Pin,
		ROW5_Pin,
		ROW6_Pin,
		ROW7_Pin
};

GPIO_TypeDef *PORT_OF_COL[8] = {
		ENM0_GPIO_Port,
		ENM1_GPIO_Port,
		ENM2_GPIO_Port,
		ENM3_GPIO_Port,
		ENM4_GPIO_Port,
		ENM5_GPIO_Port,
		ENM6_GPIO_Port,
		ENM7_GPIO_Port,
};

uint16_t PIN_OF_COL[8] = {
		ENM0_Pin,
		ENM1_Pin,
		ENM2_Pin,
		ENM3_Pin,
		ENM4_Pin,
		ENM5_Pin,
		ENM6_Pin,
		ENM7_Pin
};

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] =
{
		0b00011000,
		0b00111100,
		0b01100110,
		0b01100110,
		0b01111110,
		0b01111110,
		0b01100110,
		0b01100110
};


void exercise9_init()
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
	setTimer(TIMER_MATRIX, TIME_MATRIX);
}

void exercise9_run()
{
	if (isFlag(TIMER_MATRIX))
	{
		updateLEDMatrix(index_led_matrix);

		++index_led_matrix;
		if (index_led_matrix >= 8)
		{
			index_led_matrix = 0;
		}

		setTimer(TIMER_MATRIX, TIME_MATRIX);
	}
}

void updateLEDMatrix(int idx)
{
	switch (idx) {
		case 0:
			// Display the ROW0 with matrix_buffer[0]
			enableRow(0);
			displayRow(matrix_buffer[0]);
			break;
		case 1:
			// Display the ROW1 with matrix_buffer[1]
			enableRow(1);
			displayRow(matrix_buffer[1]);
			break;
		case 2:
			// Display the ROW2 with matrix_buffer[2]
			enableRow(2);
			displayRow(matrix_buffer[2]);
			break;
		case 3:
			// Display the ROW3 with matrix_buffer[3]
			enableRow(3);
			displayRow(matrix_buffer[3]);
			break;
		case 4:
			// Display the ROW4 with matrix_buffer[4]
			enableRow(4);
			displayRow(matrix_buffer[4]);
			break;
		case 5:
			// Display the ROW5 with matrix_buffer[5]
			enableRow(5);
			displayRow(matrix_buffer[5]);
			break;
		case 6:
			// Display the ROW6 with matrix_buffer[6]
			enableRow(6);
			displayRow(matrix_buffer[6]);
			break;
		case 7:
			// Display the ROW7 with matrix_buffer[7]
			enableRow(7);
			displayRow(matrix_buffer[7]);
			break;
		default:
			break;
	}
}

void displayRow(uint8_t buffer_data)
{
	uint8_t temp;
	for (int i = 0; i < 8; ++i)
	{
		temp = buffer_data & 0b10000000;
		if (temp == 0b10000000)
		{
			HAL_GPIO_WritePin(PORT_OF_COL[i], PIN_OF_COL[i], ENABLE_LED);
		}
		if (temp == 0b00000000)
		{
			HAL_GPIO_WritePin(PORT_OF_COL[i], PIN_OF_COL[i], UNABLE_LED);
		}
		buffer_data = buffer_data << 1;
	}
}

void enableRow(int idx)
{
	switch (idx) {
		case 0:
			ROW0_ON;
			ROW1_OFF;
			ROW2_OFF;
			ROW3_OFF;
			ROW4_OFF;
			ROW5_OFF;
			ROW6_OFF;
			ROW7_OFF;
			break;
		case 1:
			ROW0_OFF;
			ROW1_ON;
			ROW2_OFF;
			ROW3_OFF;
			ROW4_OFF;
			ROW5_OFF;
			ROW6_OFF;
			ROW7_OFF;
			break;
		case 2:
			ROW0_OFF;
			ROW1_OFF;
			ROW2_ON;
			ROW3_OFF;
			ROW4_OFF;
			ROW5_OFF;
			ROW6_OFF;
			ROW7_OFF;
			break;
		case 3:
			ROW0_OFF;
			ROW1_OFF;
			ROW2_OFF;
			ROW3_ON;
			ROW4_OFF;
			ROW5_OFF;
			ROW6_OFF;
			ROW7_OFF;
			break;
		case 4:
			ROW0_OFF;
			ROW1_OFF;
			ROW2_OFF;
			ROW3_OFF;
			ROW4_ON;
			ROW5_OFF;
			ROW6_OFF;
			ROW7_OFF;
			break;
		case 5:
			ROW0_OFF;
			ROW1_OFF;
			ROW2_OFF;
			ROW3_OFF;
			ROW4_OFF;
			ROW5_ON;
			ROW6_OFF;
			ROW7_OFF;
			break;
		case 6:
			ROW0_OFF;
			ROW1_OFF;
			ROW2_OFF;
			ROW3_OFF;
			ROW4_OFF;
			ROW5_OFF;
			ROW6_ON;
			ROW7_OFF;
			break;
		case 7:
			ROW0_OFF;
			ROW1_OFF;
			ROW2_OFF;
			ROW3_OFF;
			ROW4_OFF;
			ROW5_OFF;
			ROW6_OFF;
			ROW7_ON;
			break;
		default:
			break;
	}
}
