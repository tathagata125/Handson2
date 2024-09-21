/* name - 8c
 author : Tathagata Das
 Description - Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date - 20th sept 2024
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigfpe(int signum) {
    printf("Caught signal %d (SIGFPE): Floating-point exception occurred!\n", signum);
    exit(EXIT_FAILURE);  
}

int main() {
    
    if (signal(SIGFPE, handle_sigfpe) == SIG_ERR) {
        perror("Failed to set up SIGFPE handler");
        return EXIT_FAILURE;
    }

    printf("Signal handler for SIGFPE is set up.\n");

    // Deliberately trigger a floating-point exception (division by zero)
    int x = 5;
    int y = 0;
    int result = x / y;  // This will generate a SIGFPE signal

    // The following line will not be executed because of the SIGFPE
    printf("Result of division: %d\n", result);

    return 0;
}
