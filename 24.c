/* name - 24
 author : Tathagata Das
.description - Write a program to create a message queue and print the key and message queue id.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main() {
    // Define a key for the message queue
    key_t key = ftok("msgqueuefile", 65); // Use a file and a project identifier
    if (key == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Create a message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    // Print the key and the message queue ID
    printf("Message Queue created with Key: %d and ID: %d\n", key, msgid);

    // Clean up: remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    return 0;
}

