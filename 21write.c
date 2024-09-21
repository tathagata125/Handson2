/* name - 21
 author : Tathagata Das
.description - Write two programs so that both can communicate by FIFO -Use two way communications.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *fifo1 = "fifo1"; // FIFO for sending to Reader
    const char *fifo2 = "fifo2"; // FIFO for receiving from Reader
    char *message = "Hello from Writer 1!\n";
    char buffer[100];

    // Create FIFOs if they don't exist
    mkfifo(fifo1, 0666);
    mkfifo(fifo2, 0666);

    // Open the FIFO for writing
    int fd1 = open(fifo1, O_WRONLY);
    
    // Open the FIFO for reading
    int fd2 = open(fifo2, O_RDONLY);
    
    // Write a message to the Reader
    write(fd1, message, strlen(message) + 1);
    printf("Writer 1: Sent message: %s", message);
    
    // Read a response from the Reader
    read(fd2, buffer, sizeof(buffer));
    printf("Writer 1: Received message: %s", buffer);
    
    // Close the FIFOs
    close(fd1);
    close(fd2);
    
    // Remove the FIFOs
    unlink(fifo1);
    unlink(fifo2);

    return 0;
}

