/* name - 29
 author : Tathagata Das
.description -  Write a program to remove the message queue.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        return EXIT_FAILURE;
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

