/* name - 11
 author : Tathagata Das
 Description -Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

// Handler for SIGINT (not used since we're ignoring it)
void ignore_sigint(int signum) {
    
}

int main() {
    struct sigaction sa;

    
    sa.sa_handler = ignore_sigint;     
    
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is now ignored. Press Ctrl+C to test.\n");

    
    sleep(5);

    
    sa.sa_handler = SIG_DFL;           
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT handler reset to default. Press Ctrl+C to terminate the program.\n");

    
    while (1) {
        pause(); 
    }

    
}

