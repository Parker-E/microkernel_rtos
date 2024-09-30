#include "semaphore.h"

void init_semaphore(semaphore_t *s, int value) {
    s->value = value;
}

void wait_semaphore(semaphore_t *s) {
    while (__sync_lock_test_and_set(&s->value, s->value - 1) < 0) {
        __sync_lock_test_and_set(&s->value, s->value + 1);
    }
}

void signal_semaphore(semaphore_t *s) {
    __sync_lock_test_and_set(&s->value, s->value + 1);
}