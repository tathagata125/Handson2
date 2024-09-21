/* name - 15
 author : Tathagata Das
 Description -Write a simple program to send some data from parent to the child process.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    pid_t pid;
    char buffer[100]; 
    
    pipe(pipefd) ;
    
    pid = fork();
    

    if (pid > 0) {
        
        const char *message = "Hello from the parent process!";
        
        // Close the read end of the pipe in the parent
        close(pipefd[0]); 
        
        // Write to the pipe
        write(pipefd[1], message, strlen(message) + 1); // +1 for null terminator
        
        // Close the write end after writing
        close(pipefd[1]); 
    } else {
        // Child process
        // Close the write end of the pipe in the child
        close(pipefd[1]); 
        
        // Read from the pipe
        read(pipefd[0], buffer, sizeof(buffer)); 
        printf("Child received: %s\n", buffer);
        
        // Close the read end after reading
        close(pipefd[0]); 
    }

    return 0;
}

