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
