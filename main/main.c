#include <stdio.h>
#include "common.h"
#include "kernel.h"
#include "task.h"
#include "ipc.h"

void delay(int millis) {
    int count = millis * 10000;
    while (count--) {
        __asm__("nop");
    }
}

void task1() {
    printf("Task 1 running\n");
    tasks[0].state = WAITING;
    send_message(0, 1, "Hello from Task 1");
    delay(1000);
    tasks[0].state = READY;
}

void task2() {
    printf("Task 2 running\n");
    const char *msg = receive_message(1);
    if (msg != NULL) {
        printf("Task 2 received: %s\n", msg);
    }
    delay(1000);
}

void app_main() {
    kernel_init();
    create_task(task1, "Task 1", 0);
    create_task(task2, "Task 2", 1);
    kernel_start();
}