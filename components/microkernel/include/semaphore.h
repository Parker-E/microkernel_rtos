#ifndef SEMAPHORE_H
#define SEMAPHORE_H

typedef struct {
    int value;
} semaphore_t;

void init_semaphore(semaphore_t *s, int value);
void wait_semaphore(semaphore_t *s);
void signal_semaphore(semaphore_t *s);

#endif // SEMAPHORE_H