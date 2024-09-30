#include <stdio.h>
#include "kernel.h"
#include "task.h"
#include "common.h"

void delay(int millis) {
    int count = millis * 10000;
    while (count--) {
        __asm__("nop");
    }
}

void task1() {
    printf("Task 1 running\n");
    delay(1000);
}

void task2() {
    printf("Task 2 running\n");
    delay(1000);
}

void app_main() {
    kernel_init();
    create_task(task1, "Task 1", 0);
    create_task(task2, "Task 2", 1);
    kernel_start();
}