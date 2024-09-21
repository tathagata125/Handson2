/* name - 8g
 author : Tathagata Das
 Description - Write a separate program using signal system call to catch the following signals.
g. SIGPROF (use setitimer system call)
Date - 20th sept 2024
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>


void handle_sigprof(int signum) {
    printf("Caught signal %d (SIGPROF): Profiling timer expired!\n", signum);
}

int main() {
    struct itimerval timer;

   
    if (signal(SIGPROF, handle_sigprof) == SIG_ERR) {
        perror("Failed to set up SIGPROF handler");
        return EXIT_FAILURE;
    }

    
    timer.it_value.tv_sec = 2;       
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;    
    timer.it_interval.tv_usec = 0;

   
    setitimer(ITIMER_PROF, &timer, NULL);
    printf("Waiting for profiling timer alarm signal...\n");
    while(1){
      sleep(2);
    }
    return 0;
}

