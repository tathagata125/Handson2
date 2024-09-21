/* name - 17b
 author : Tathagata Das
 Description -Write a program to execute ls -l | wc.
b. use dup2
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

    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    
    pid = fork();

    if (pid < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        
        
        close(pipefd[0]); 

        
        dup2(pipefd[1], STDOUT_FILENO);

        
        close(pipefd[1]);

        
        execlp("ls", "ls", "-l", NULL);

        
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        
        
        close(pipefd[1]); 
        
        dup2(pipefd[0], STDIN_FILENO);

        
        close(pipefd[0]);

        execlp("wc", "wc", NULL);

        
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    
    wait(NULL);

    return 0;
}

