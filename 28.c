/* name - 28
 author : Tathagata Das
.description -  Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

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

    // Create an msqid_ds structure to hold message queue attributes
    struct msqid_ds msg_queue_info;

    // Retrieve current message queue information
    if (msgctl(msgid, IPC_STAT, &msg_queue_info) == -1) {
        perror("msgctl IPC_STAT");
        return EXIT_FAILURE;
    }

    // Display current permissions
    printf("Current permissions: %o\n", msg_queue_info.msg_perm.mode);

    // Change permissions (e.g., set to 0666 for read/write access)
    msg_queue_info.msg_perm.mode = 0666; // Set new permissions

    // Apply the new permissions
    if (msgctl(msgid, IPC_SET, &msg_queue_info) == -1) {
        perror("msgctl IPC_SET");
        return EXIT_FAILURE;
    }

    printf("Permissions changed to: %o\n", msg_queue_info.msg_perm.mode);

    return 0;
}

