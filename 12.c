/* name - 12
 author : Tathagata Das
 Description -Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork(); 
   if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) created. Sending SIGKILL to parent (PID: %d)...\n", getpid(), getppid());
        kill(getppid(), SIGKILL); 
    } else {
        
        printf("Parent process (PID: %d) waiting for child to send SIGKILL...\n", getpid());
        
        printf("This line will not be printed as parent is killed.\n");
    }

    
    sleep(2);
    printf("Child process (PID: %d) is now an orphan.\n", getpid());

    
}
