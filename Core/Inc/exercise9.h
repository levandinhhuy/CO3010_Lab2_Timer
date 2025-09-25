/*
 * exercise9.h
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#ifndef INC_EXERCISE9_H_
#define INC_EXERCISE9_H_

#include "main.h"
#include "software_timer.h"

void exercise9_init();
void exercise9_run();

void updateLEDMatrix(int idx);
void displayRow(uint8_t buffer_data);
void enableRow(int idx);

#endif /* INC_EXERCISE9_H_ */
