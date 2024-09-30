#include <stdio.h>
#include "common.h"
#include "kernel.h"
#include "task.h"
#include "ipc.h"
#include "mutex.h"
#include "semaphore.h"
#include "event_flags.h"

semaphore_t sem;
mutex_t mut;
event_flags_t evt;

void delay(int millis) {
    int count = millis * 10000;
    while (count--) {
        __asm__("nop");
    }
}

void task1() {
    printf("Task 1 running\n");
    send_message(0, 1, "Hello from Task 1");
    set_event(&evt, 0x01);
    signal_semaphore(&sem);
}

void task2() {
    if (wait_event(&evt, 0x01)) {
        clear_event(&evt, 0x01);
        lock_mutex(&mut);
        printf("Task 2 running\n");
        const char *msg = receive_message(1);
        if (msg != NULL) {
            printf("Task 2 received: %s\n", msg);
        }
        unlock_mutex(&mut);
        wait_semaphore(&sem);
    }
}

void task3() {
    printf("Task 3 running\n");
    delay(1500);
}

void app_main() {
    kernel_init();
    init_semaphore(&sem, 0);
    init_mutex(&mut);
    evt.flags = 0;

    create_task(task1, "Task 1", 0);
    create_task(task2, "Task 2", 1);
    create_task(task3, "Task 3", 2);

    kernel_start();
}