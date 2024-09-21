/* name - 10a
 author : Tathagata Das
 Description -Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV 
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

// Signal handler for SIGSEGV
void handle_sigsegv(int signum) {
    printf("Caught signal %d (SIGSEGV): Segmentation fault occurred!\n", signum);
    exit(EXIT_FAILURE);  
}

int main() {
    struct sigaction sa;

    // Set up the sigaction structure
    sa.sa_handler = handle_sigsegv;   // Set the signal handler
    

   
    sigaction(SIGSEGV, &sa, NULL);

    printf("SIGSEGV handler installed. About to cause a segmentation fault...\n");

    
    int *ptr = NULL;  
    *ptr = 42;
}


