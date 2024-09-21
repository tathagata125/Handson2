/* name - 17a
 author : Tathagata Das
 Description -Write a program to execute ls -l | wc.
a. use dup
communication.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];  
    pid_t pid;

    
    pipe(pipefd) ;

    pid = fork();
    if (pid == 0) {
        
        close(pipefd[0]);

        
        close(STDOUT_FILENO);      
        dup(pipefd[1]);

        
        close(pipefd[1]);

        
        execlp("ls", "ls", "-l", NULL);

        
    } else {
        
        close(pipefd[1]);

        
        close(STDIN_FILENO);       
        dup(pipefd[0]);

        
        close(pipefd[0]);

        
        execlp("wc", "wc", NULL);

        
    }

    return 0;
}

