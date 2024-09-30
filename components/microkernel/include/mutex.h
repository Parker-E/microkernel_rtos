#ifndef MUTEX_H
#define MUTEX_H

typedef struct {
    int locked;
} mutex_t;

void init_mutex(mutex_t *m);
void lock_mutex(mutex_t *m);
void unlock_mutex(mutex_t *m);

#endif // MUTEX_H