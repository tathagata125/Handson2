/* name - 8f
 author : Tathagata Das
 Description - Write a separate program using signal system call to catch the following signals.
SIGVTALRM (use setitimer system call)
Date - 20th sept 2024
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

// Signal handler function for SIGVTALRM
void handle_sigvtalrm(int signum) {
    printf("Caught signal %d (SIGVTALRM): Virtual timer expired!\n", signum);
}

int main() {
    struct itimerval timer;

    
    if (signal(SIGVTALRM, handle_sigvtalrm) == SIG_ERR) {
        perror("Failed to set up SIGVTALRM handler");
        return EXIT_FAILURE;
    }

    
    timer.it_value.tv_sec = 1;       
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;    
    timer.it_interval.tv_usec = 500000;

    // Start the virtual timer (ITIMER_VIRTUAL)
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Failed to set virtual timer");
        return EXIT_FAILURE;
    }

    printf("Virtual timer started: first alarm in 1 second, then every 500 milliseconds.\n");

    
    while (1) {
        for (int i = 0; i < 100000000; i++) {
            // Simulate CPU work in user mode
        }
        printf("Working...\n");
    }

    return 0;
}

