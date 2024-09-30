#ifndef TASK_H
#define TASK_H

void create_task(void (*task_func)(), const char *name, int task_id);

#endif // TASK_H