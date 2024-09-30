#ifndef EVENT_FLAGS_H
#define EVENT_FLAGS_H

typedef struct {
    uint32_t flags;
} event_flags_t;

void set_event(event_flags_t *e, uint32_t flag);
void clear_event(event_flags_t *e, uint32_t flag);
uint32_t wait_event(event_flags_t *e, uint32_t flag);

#endif // EVENT_FLAGS_H