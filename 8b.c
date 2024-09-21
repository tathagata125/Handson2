/* name - 8b
 author : Tathagata Das
 Description - Write a separate program using signal system call to catch the following signals.
 SIGINT
Date - 20th sept 2024
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigint(int signum) {
    printf("\nCaught signal %d (SIGINT): Interrupt signal received. Exiting program...\n", signum);
    exit(EXIT_SUCCESS);  
}

int main() {
    
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("Failed to set up SIGINT handler");
        return EXIT_FAILURE;
    }

    printf("Signal handler for SIGINT is set up. Press Ctrl+C to trigger it.\n");

    
    while (1) {
        printf("Program is running... Press Ctrl+C to send SIGINT.\n");
        sleep(1);  // Sleep for 1 second to slow down the loop
    }

    return 0;
}
