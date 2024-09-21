/* name - 9
 author : Tathagata Das
 Description - Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void reset_sigint(int signum) {
    printf("Resetting SIGINT to default action.\n");

    
    signal(SIGINT, SIG_DFL) ;
}

int main() {
    // Ignore SIGINT (Ctrl+C)
    signal(SIGINT, SIG_IGN)  ;
    
    printf("SIGINT signal is now ignored. Press Ctrl+C, but it won't terminate the program.\n");

    
    sleep(5);

    
    signal(SIGALRM, reset_sigint) ;
    alarm(2);

    printf("SIGINT will be reset to default action after 2 seconds. Press Ctrl+C again after that.\n");

    
    while (1) {
        pause(); 
    }

    return 0;
}

