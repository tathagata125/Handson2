/* name - 31b
 author : Tathagata Das
.description -Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
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

    // Create a counting semaphore
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return EXIT_FAILURE;
    }

    // Initialize the semaphore to 5 (counting semaphore)
    if (semctl(semid, 0, SETVAL, 5) == -1) {
        perror("semctl SETVAL");
        return EXIT_FAILURE;
    }

    printf("Counting semaphore created and initialized successfully with ID: %d\n", semid);
    return 0;
}

