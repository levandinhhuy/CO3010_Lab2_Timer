/*
 * exercise6.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "exercise6.h"
#include "software_timer.h"

void exercise6_init()
{

}

void exercise6_run()
{
	setTimer0(10);
	while (1){
		if (timer0_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer0(2000);
		}
	}
}
