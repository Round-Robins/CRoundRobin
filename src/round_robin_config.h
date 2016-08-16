/*
 * round_robin_config.h
 *
 *  Created on: Apr 28, 2016
 *      Author: lucas
 */

#ifndef ROUND_ROBIN_CONFIG_H_
#define ROUND_ROBIN_CONFIG_H_

#define TASK_PERIOD_MS (0.001)

#define CALIBRATE_LOADING (0)

#ifndef NUMBER_OF_TASKS
#define NUMBER_OF_TASKS (1)
#endif

#ifndef USE_IDLE_TASK
#define USE_IDLE_TASK (1)
#endif

#ifndef RECORD_TASK_TIMES
#define RECORD_TASK_TIMES (0)
#endif

#ifndef ONLY_RECORD_MAX_TASK_TIME
#define ONLY_RECORD_MAX_TASK_TIME (0)
#endif

#endif /* ROUND_ROBIN_CONFIG_H_ */
