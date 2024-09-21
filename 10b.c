/* name - 10b
 author : Tathagata Das
 Description -Write a separate program using sigaction system call to catch the following signals.
a. SIGINT
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>


void handle_sigint(int signum) {
    printf("Caught signal %d (SIGINT): Interrupt signal received!\n", signum);
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;

    
    sa.sa_handler = handle_sigint;     

    
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    printf("SIGINT handler installed. Press Ctrl+C to trigger the signal.\n");

    
    while (1) {
        pause(); // Wait for signals
        
    }

    
}

