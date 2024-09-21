/*name - 8a
Author - Tathgata Das
Roll number - MT2024161
Description - Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date - 20th sept 2024*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler function
void handle_sigsegv(int signum) {
    printf("Caught signal %d (SIGSEGV): Segmentation Fault occurred!\n", signum);
    exit(EXIT_FAILURE); 
}

int main() {
    
    if (signal(SIGSEGV, handle_sigsegv) == SIG_ERR) {
        perror("Failed to set up SIGSEGV handler");
        return EXIT_FAILURE;
    }

    printf("Signal handler for SIGSEGV is set up.\n");

    // Cause a segmentation fault by dereferencing a NULL pointer
    int *ptr = NULL;
    *ptr = 42; // This will generate a SIGSEGV signal

    return 0;
}
