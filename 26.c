/* name - 26
 author : Tathagata Das
.description - Write a program to send messages to the message queue. Check $ipcs -q
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
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    // Prepare and send messages
    struct message msg;
    msg.msg_type = 1; // Set message type

    for (int i = 0; i < 5; i++) {
        snprintf(msg.msg_text, MAX_TEXT, "Message %d", i + 1);
        
        // Send the message to the queue
        if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd");
            return EXIT_FAILURE;
        }

        printf("Sent: %s\n", msg.msg_text);
        sleep(1); // Wait for 1 second before sending the next message
    }

    return 0;
}

