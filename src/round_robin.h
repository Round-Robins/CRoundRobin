#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_

#include "round_robin_config.h"
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

int GetRoundRobinLoading(void);

void TimerTrigger(void);

extern long GetTimerCounts(void);

extern void RoundRobinIdle(void);

#endif /* ROUND_ROBIN_H_ */
