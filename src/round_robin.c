/*
 * round_robin.c
 *
 *  Created on: Apr 28, 2016
 *      Author: lucas
 */

#include "round_robin.h"

static RRTask_T Tasks[NUMBER_OF_TASKS] = { };
static bool timer_is_triggered = false;
static bool
isTimerTriggered(void);

bool RoundRobinTaskCreate(RRTask_T* task) {
	static uint16_t assignedTasks = 0;
	bool isGood = true;

	if (assignedTasks < NUMBER_OF_TASKS && task->period_count > 0) {
		Tasks[assignedTasks] = *task;
	} else {
		isGood = false;
	}

	return isGood;
}

bool RoundRobinInit() {
	bool ret = true;

	for (uint16_t i = 0; i < NUMBER_OF_TASKS; i++) {
		Tasks[i].counter = Tasks[i].offset;
	}
	return ret;
}

void RoundRobinStart() {
#if RECORD_TASK_TIMES == 1
	static uint32_t taskTime = 0;
#endif
	for (;;) {
		if (isTimerTriggered()) {
			for (uint16_t i = 0; i < NUMBER_OF_TASKS; i++) {
				if (++Tasks[i].counter >= Tasks[i].period_count) {
					Tasks[i].counter = 0;
#if RECORD_TASK_TIMES == 1
					taskTime = get_timer_counts();
#endif
					Tasks[i].callback();
#if RECORD_TASK_TIMES == 1
					Tasks[i].task_time = taskTime - get_timer_counts();
#endif
					break; // Only run one task per loop
				}
			}
		} else {
#if USE_IDLE_TASK == 1
			RoundRobinIdle();
#endif
		}
	}
}

uint16_t GetRoundRobinLoading() {
	uint16_t percentLoad = 0;

	for(uint8_t i = 0; i < NUMBER_OF_TASKS; i++)
	{

	}

	return percentLoad;
}

void TimerTrigger() {
	timer_is_triggered = true;
}

static bool isTimerTriggered() {
	return timer_is_triggered;
}
