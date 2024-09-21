/* name - 14
 author : Tathagata Das
 Description -Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    char buffer[100]; 
    pipe(pipefd) ;

    // Write to the pipe
    const char *message = "Hello, this is a message from the pipe!";
    write(pipefd[1], message, strlen(message) + 1); 

    // Read from the pipe
    read(pipefd[0], buffer, sizeof(buffer)); 
    printf("Message read from pipe: %s\n", buffer);

    close(pipefd[0]);
    close(pipefd[1]);

}

