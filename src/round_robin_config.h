
#ifndef ROUND_ROBIN_CONFIG_H_
#define ROUND_ROBIN_CONFIG_H_

/// Period of a single task cycle
#define TASK_PERIOD_MS (1)

/// Period of a cycle to calculate CPU loading
#define CPU_LOADING_PERIOD_MS (1000)

#ifndef NUMBER_OF_TASKS
#define NUMBER_OF_TASKS (1) ///< Number of allowed tasks
#endif

//#define USE_IDLE_TASK

//#define RECORD_TASK_TIMES

//#define ONLY_RECORD_MAX_TASK_TIME

#endif /* ROUND_ROBIN_CONFIG_H_ */
