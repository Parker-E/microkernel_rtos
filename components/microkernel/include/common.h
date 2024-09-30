#ifndef COMMON_H
#define COMMON_H

#define STACK_SIZE 1024
#define MAX_TASKS 10

typedef enum { READY, RUNNING, WAITING } task_state_t;

typedef struct {
    void (*task_func)();
    const char *name;
    uint32_t *stack_pointer;
    task_state_t state;
} task_t;

extern task_t tasks[MAX_TASKS];
extern int current_task_id;

#endif // COMMON_H
