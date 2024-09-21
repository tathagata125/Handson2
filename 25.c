/* name - 25
 author : Tathagata Das
.description - Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
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

    // Create an msqid_ds structure to hold the message queue attributes
    struct msqid_ds msg_queue_info;

    // Retrieve message queue information
    if (msgctl(msgid, IPC_STAT, &msg_queue_info) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    // Print access permissions
    printf("Access Permissions: %o\n", msg_queue_info.msg_perm.mode);
    
    // Print uid and gid
    printf("User ID (UID): %d\n", msg_queue_info.msg_perm.uid);
    printf("Group ID (GID): %d\n", msg_queue_info.msg_perm.gid);
    
    // Print times of last message sent and received
    printf("Time of Last Message Sent: %s", ctime(&msg_queue_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msg_queue_info.msg_rtime));
    
    // Print time of last change in the message queue
    printf("Time of Last Change: %s", ctime(&msg_queue_info.msg_ctime));
    
    // Print size of the queue
    printf("Current Size of Queue: %lu bytes\n", msg_queue_info.__msg_cbytes);
    
    // Print number of messages in the queue
    printf("Number of Messages in Queue: %lu\n", msg_queue_info.msg_qnum);
    
    // Print maximum number of bytes allowed
    printf("Maximum Number of Bytes Allowed: %lu\n", msg_queue_info.msg_qbytes);
    
    // Print PID of last msgsnd and msgrcv
    printf("PID of Last msgsnd: %d\n", msg_queue_info.msg_lspid);
    printf("PID of Last msgrcv: %d\n", msg_queue_info.msg_lrpid);

    return 0;
}

