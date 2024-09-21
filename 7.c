/*name - 7
Author - Tathgata Das
Roll number - MT2024161
Write a simple program to print the created thread ids.
Date - 20th sept 2024*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self(); // Get the thread ID
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    
    
    for (int i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

  
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished execution.\n");
    
    return 0;

}
