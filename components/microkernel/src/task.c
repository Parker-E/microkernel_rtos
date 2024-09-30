#include "stdint.h"
#include "task.h"
#include "common.h"

uint32_t task_stacks[MAX_TASKS][STACK_SIZE];

void create_task(void (*task_func)(), const char *name, int task_id) {
    tasks[task_id].task_func = task_func;
    tasks[task_id].name = name;
    tasks[task_id].stack_pointer = &task_stacks[task_id][STACK_SIZE - 1];
    tasks[task_id].state = READY;
}