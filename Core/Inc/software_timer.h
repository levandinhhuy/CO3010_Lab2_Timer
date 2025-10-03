/*
 * software_timer.h
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

struct TimerStruct
{
	int counter;
	int flag;
};

extern struct TimerStruct timer[10];

extern int timer0_counter;
extern int timer0_flag;
extern int TIMER_CYCLE;

void setTimer(int idx, int counter);
void timerRun();
int isFlag(int idx);
void setTimer0(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
