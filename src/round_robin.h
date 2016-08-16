/*
 * round_robin.h
 *
 *  Created on: Apr 28, 2016
 *      Author: lucas
 */

#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_

#include "round_robin_config.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct RRTask_S {
	uint16_t period_ms;
	uint16_t offset;
	void (*callback)();
	uint32_t counter;
	uint32_t period_count;
	uint32_t task_time;
} RRTask_T;

#define RRTASK(func) task_##func

#define RRTASK_DEF(func, period, offset) static RRTask_T task_##func = {.period_ms = period, offset, func, 0, (period / TASK_PERIOD_MS)}

bool RoundRobinTaskCreate(RRTask_T* task);

bool RoundRobinInit(void);

void RoundRobinStart(void);

uint16_t GetRoundRobinLoading(void);

void TimerTrigger(void);

extern uint32_t GetTimerCounts(void);

extern void RoundRobinIdle(void);

#endif /* ROUND_ROBIN_H_ */
