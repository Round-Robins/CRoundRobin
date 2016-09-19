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

#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_

#include <stdbool.h>

typedef struct RRTask_S {
	int period_ms;
	int offset;
	void (*callback)();
	long counter;
	long period_count;
	long task_time;
} RRTask_T;

#define RRTASK(func) task_##func

#define RRTASK_DEF(func, period, offset) static RRTask_T task_##func = {.period_ms = period, offset, func, 0, (period / TASK_PERIOD_MS)}

bool RoundRobinTaskCreate(RRTask_T* task);

bool RoundRobinInit(void);

void RoundRobinStart(void);

int RoundRobinGetLoading(void);

void RoundRobinTimerTrigger(void);

extern long RoundRobinGetTimerCounts(void);

extern void RoundRobinIdle(void);

#endif /* ROUND_ROBIN_H_ */
