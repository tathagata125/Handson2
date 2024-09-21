/* name - 10c
 author : Tathagata Das
 Description -Write a separate program using sigaction system call to catch the following signals.
a. SIGFPE
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>


void handle_sigfpe(int signum) {
    printf("Caught signal %d (SIGFPE): Floating-point exception occurred!\n", signum);
    exit(EXIT_FAILURE);   
}

int main() {
    struct sigaction sa;

    
    sa.sa_handler = handle_sigfpe;    

    
    sigaction(SIGFPE, &sa, NULL);

    printf("SIGFPE handler installed. About to cause a floating-point exception...\n");

    
    int x = 1;
    int y = 0;
    int z = x / y;  
}

