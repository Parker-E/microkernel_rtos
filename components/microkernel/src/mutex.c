#include "mutex.h"

void init_mutex(mutex_t *m) {
    m->locked = 0;
}

void lock_mutex(mutex_t *m) {
    while (__sync_lock_test_and_set(&m->locked, 1)) {}
}

void unlock_mutex(mutex_t *m) {
    __sync_lock_release(&m->locked);
}