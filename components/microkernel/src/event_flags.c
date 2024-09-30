#include "stdint.h"
#include "event_flags.h"

void set_event(event_flags_t *e, uint32_t flag) {
    e->flags |= flag;
}

void clear_event(event_flags_t *e, uint32_t flag) {
    e->flags &= ~flag;
}

uint32_t wait_event(event_flags_t *e, uint32_t flag) {
    while ((e->flags & flag) == 0) {
        // Busy wait
    }
    return e->flags;
}