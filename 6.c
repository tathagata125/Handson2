/* name - 6
 author : Tathagata Das
 Description - Write a simple program to create three threads.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

// Function to be executed by each thread
void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d: Hello from the thread!\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];
    
    // Create three threads
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution.\n");
    
    return 0;
}
