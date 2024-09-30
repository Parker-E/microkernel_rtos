#include "stdio.h"
#include "stdint.h"
#include "stddef.h"
#include "kernel.h"
#include "task.h"
#include "common.h"

task_t tasks[MAX_TASKS];
int current_task_id;

typedef struct {
    uint32_t *stack_pointer;
} tcb_t;

void kernel_init() {
    // Init tasks to be empty
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].task_func = NULL;
    }
    current_task_id = -1;
}

void kernel_start() {
    // Run through each task
    while (1) {
        if (tasks[current_task_id].task_func != NULL && tasks[current_task_id].state == READY) {
            tasks[current_task_id].state = RUNNING;
            tasks[current_task_id].task_func();
            tasks[current_task_id].state = READY;
        }
        __asm__("nop"); // Break for context switch debug
        current_task_id = (current_task_id + 1) % MAX_TASKS;
    }
}