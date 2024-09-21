/* name - 17c
 author : Tathagata Das
 Description -Write a program to execute ls -l | wc. c. use fcntl
communication.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int pipefd[2];  
    pid_t pid;

    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    
    pid = fork();

    
    if (pid == 0) {
        
        
        close(pipefd[0]); 

        
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);

        
        close(pipefd[1]);

        
        execlp("ls", "ls", "-l", NULL);

        
    } else {
        
        close(pipefd[1]); 

        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);

        
        close(pipefd[0]);

        
        execlp("wc", "wc", NULL);

        perror("execlp");
        exit(EXIT_FAILURE);
    }

    wait(NULL);

    return 0;
}

