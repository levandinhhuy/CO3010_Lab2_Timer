/*
 * software_timer.c
 *
 *  Created on: Sep 25, 2025
 *      Author: dinhh
 */

#include "software_timer.h"

#define TICK 10

struct TimerStruct timer[10];

int timer0_counter = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10;

void setTimer(int idx, int counter)
{
	timer[idx].counter = counter / TICK;
	timer[idx].flag = 0;
}

void timerRun()
{
	for (int i = 0; i < 10; ++i)
	{
		if (timer[i].counter > 0)
		{
			--timer[i].counter;
			if (timer[i].counter <= 0)
			{
				timer[i].flag = 1;
			}
		}
	}
}

int isFlag(int idx)
{
	if (timer[idx].flag)
	{
		return 1;
	}
	return 0;
}

void setTimer0(int duration){
	 timer0_counter = duration /TIMER_CYCLE;
	 timer0_flag = 0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0)
			timer0_flag = 1;
	}
}
