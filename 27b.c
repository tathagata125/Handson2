/* name - 27b
 author : Tathagata Das
.description -  Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define MAX_TEXT 100

// Message structure
struct message {
    long msg_type;
    char msg_text[MAX_TEXT];
};

int main() {
    // Define a key for the message queue
    key_t key = ftok("msgqueuefile", 65);
    if (key == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Get the message queue ID
    int msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    struct message msg;

    // Receive messages with 0 flag (blocking)
    while (1) {
        if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, 0) == -1) {
            perror("msgrcv");
            return EXIT_FAILURE;
        }
        printf("Received: %s\n", msg.msg_text);
    }

    return 0;
}

