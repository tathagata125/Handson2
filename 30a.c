/* name - 30a
 author : Tathagata Das
.description -  Write a program to create a shared memory.
a. write some data to the shared memory
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024  // Size of shared memory segment

int main() {
    // Generate a unique key for the shared memory
    key_t key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Create a shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return EXIT_FAILURE;
    }

    // Attach the shared memory segment to our process
    char *data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        return EXIT_FAILURE;
    }

    // Write some data to the shared memory
    const char *message = "Hello, this is a message in shared memory!";
    strncpy(data, message, SHM_SIZE);

    printf("Data written to shared memory: %s\n", data);

    // Detach the shared memory segment
    if (shmdt(data) == -1) {
        perror("shmdt");
        return EXIT_FAILURE;
    }

    return 0;
}

