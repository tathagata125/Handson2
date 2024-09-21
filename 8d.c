/* name - 8d
 author : Tathagata Das
 Description - Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date - 20th sept 2024
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handle_sigalrm(int signum) {
    printf("Caught signal %d (SIGALRM): Alarm signal received. Time's up!\n", signum);
    exit(EXIT_SUCCESS);  
}

int main() {
    
    if (signal(SIGALRM, handle_sigalrm) == SIG_ERR) {
        perror("Failed to set up SIGALRM handler");
        return EXIT_FAILURE;
    }

    printf("Alarm set for 5 seconds...\n");

    // Schedule an alarm after 5 seconds
    alarm(5);

    // Infinite loop to simulate doing some work
    while (1) {
        printf("Waiting for the alarm...\n");
        sleep(1);  // Sleep for 1 second in each iteration
    }

    return 0;
}
