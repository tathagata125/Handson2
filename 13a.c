/* name - 13
 author : Tathagata Das
 Description -Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigstop(int signum) {
    printf("Caught SIGSTOP signal: %d\n", signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigstop; // Set the handler for SIGSTOP
    

    // Attempt to set the signal handler for SIGSTOP
      sigaction(SIGSTOP, &sa, NULL);

    printf("Waiting to catch SIGSTOP signal...\n");

    
    while (1) {
        pause(); 
    }

}

