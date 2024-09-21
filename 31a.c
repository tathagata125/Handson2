/* name - 31a
 author : Tathagata Das
.description -Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore  
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    // Generate a unique key for the semaphore
    key_t key = ftok("semfile", 65);
    if (key == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Create a binary semaphore
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return EXIT_FAILURE;
    }

    // Initialize the semaphore to 1 (binary semaphore)
    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl SETVAL");
        return EXIT_FAILURE;
    }

    printf("Binary semaphore created and initialized successfully with ID: %d\n", semid);
    return 0;
}

