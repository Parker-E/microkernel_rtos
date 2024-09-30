#include "stddef.h"
#include "stdint.h"
#include "string.h"
#include "common.h"
#include "ipc.h"

message_t msg_queue[MSG_QUEUE_SIZE];
int msg_queue_start = 0;
int msg_queue_end = 0;

void send_message(int sender, int receiver, const char *message) {
    if ((msg_queue_end + 1) % MSG_QUEUE_SIZE == msg_queue_start) {
        // TODO: Queue full; handle overflow
        return;
    }
    msg_queue[msg_queue_end].sender = sender;
    msg_queue[msg_queue_end].receiver = receiver;
    strncpy(msg_queue[msg_queue_end].message, message, sizeof(msg_queue[msg_queue_end].message));
    msg_queue_end = (msg_queue_end + 1) % MSG_QUEUE_SIZE;
}

const char *receive_message(int receiver) {
    for (int i = msg_queue_start; i != msg_queue_end; i = (i + 1) % MSG_QUEUE_SIZE) {
        if (msg_queue[i].receiver == receiver) {
            const char *message = msg_queue[i].message;
            // Remove message from the queue
            msg_queue_start = (i + 1) % MSG_QUEUE_SIZE;
            return message;
        }
    }
    return NULL;
}