/**
 * Original work Copyright (c) 2016 Lucas Brendel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */

#include "round_robin.h"

static RRTask_T Tasks[NUMBER_OF_TASKS] = { };
static bool
isTimerTriggered(void);

bool RoundRobinTaskCreate(RRTask_T* task) {
	static int assignedTasks = 0;
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
	int i;

	for (i = 0; i < NUMBER_OF_TASKS; i++) {
		Tasks[i].counter = Tasks[i].offset;
	}
	return ret;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void RoundRobinStart() {
#ifdef RECORD_TASK_TIMES
	static long taskTime = 0;
#endif
    int i;
	for (;;) {
			for (i = 0; i < NUMBER_OF_TASKS; i++) {
				if (++Tasks[i].counter >= Tasks[i].period_count) {
					Tasks[i].counter = 0;
#ifdef RECORD_TASK_TIMES
					taskTime = GetTimerCounts();
#endif
					Tasks[i].callback();
#ifdef RECORD_TASK_TIMES
					Tasks[i].task_time = taskTime - GetTimerCounts();
#endif
				}
			}
		} else {
#if USE_IDLE_TASK
			RoundRobinIdle();
#endif
		}
	}
}
#pragma clang diagnostic pop

int GetRoundRobinLoading() {
	int percentLoad = 0;
	int i;

	for(i = 0; i < NUMBER_OF_TASKS; i++)
    {
        percentLoad += Tasks[i].task_time * (CPU_LOADING_PERIOD_MS / Tasks[i].period_ms);
    }
	return percentLoad;
}

void TimerTrigger() {
}

}
