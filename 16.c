/* name - 16
 author : Tathagata Das
 Description -.Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd_parent_to_child[2]; 
    int pipefd_child_to_parent[2];  
    pid_t pid;
    char parent_msg[] = "Hello from the parent!";
    char child_msg[] = "Hello from the child!";
    char buffer[100]; 

    
    if (pipe(pipefd_parent_to_child) == -1 || pipe(pipefd_child_to_parent) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }

    // Fork to create the child process
    pid = fork();
    
    if (pid > 0) {
        
        // Close the unused ends of the pipes
        close(pipefd_parent_to_child[0]); // Close read end of parent-to-child pipe
        close(pipefd_child_to_parent[1]); // Close write end of child-to-parent pipe

        
        write(pipefd_parent_to_child[1], parent_msg, strlen(parent_msg) + 1);
        close(pipefd_parent_to_child[1]); 

        
        read(pipefd_child_to_parent[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        
        close(pipefd_child_to_parent[0]);
    } else {
        
        close(pipefd_parent_to_child[1]); 
        close(pipefd_child_to_parent[0]); 

        
        read(pipefd_parent_to_child[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd_parent_to_child[0]); 

        
        write(pipefd_child_to_parent[1], child_msg, strlen(child_msg) + 1);
        close(pipefd_child_to_parent[1]); 
    }

    return 0;
}

