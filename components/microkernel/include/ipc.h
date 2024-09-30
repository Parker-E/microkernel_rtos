#ifndef IPC_H
#define IPC_H

#define MSG_QUEUE_SIZE 10

typedef struct {
    int sender;
    int receiver;
    char message[64];
} message_t;

void send_message(int sender, int receiver, const char *message);
const char *receive_message(int receiver);

#endif // IPC_H