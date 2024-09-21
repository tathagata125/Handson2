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

int main() {
    pid_t target_pid;
    printf("Enter the PID of the first program: ");
    scanf("%d", &target_pid);

    printf("Sending SIGSTOP to process with PID: %d\n", target_pid);
    kill(target_pid, SIGSTOP);

    printf("SIGSTOP signal sent. The target process is now stopped.\n");

    return 0;
}

