/* name - 21
 author : Tathagata Das
.description - Write two programs so that both can communicate by FIFO -Use two way communications.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *fifo1 = "fifo1"; // FIFO for receiving from Writer
    const char *fifo2 = "fifo2"; // FIFO for sending to Writer
    char buffer[100];
    char *response = "Hello from Reader 1!\n";

    // Open the FIFO for reading
    int fd1 = open(fifo1, O_RDONLY);
    
    // Open the FIFO for writing
    int fd2 = open(fifo2, O_WRONLY);
    
    // Read a message from the Writer
    read(fd1, buffer, sizeof(buffer));
    printf("Reader 1: Received message: %s", buffer);
    
    // Send a response back to the Writer
    write(fd2, response, strlen(response) + 1);
    printf("Reader 1: Sent message: %s", response);
    
    // Close the FIFOs
    close(fd1);
    close(fd2);
    
    return 0;
}

