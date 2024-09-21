/* name - 8e
 author : Tathagata Das
 Description - Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date - 20th sept 2024
*/
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigalrm(int signum) {
    printf("Caught signal %d (SIGALRM): Timer went off!\n", signum);
}

int main() {
    struct itimerval timer;

    
    if (signal(SIGALRM, handle_sigalrm) == SIG_ERR) {
        perror("Failed to set up SIGALRM handler");
        return EXIT_FAILURE;
    }

    // Configure the timer to expire after 2 seconds, and then every 1 second thereafter
    timer.it_value.tv_sec = 2;       // Initial delay of 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;    // Subsequent intervals of 1 second
    timer.it_interval.tv_usec = 0;

    
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
        perror("Failed to set timer");
        return EXIT_FAILURE;
    }

    printf("Timer started: first alarm in 2 seconds, then every 1 second.\n");

    
    while (1) {
        pause();  // Wait for a signal
    }

    return 0;
}

