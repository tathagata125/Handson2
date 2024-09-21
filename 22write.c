/* name - 22
 author : Tathagata Das
.description - Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main() {
    const char *fifo_name = "myfifo";
    
    // Create FIFO if it doesn't exist
    mkfifo(fifo_name, 0666);
    
    // Simulate delay before writing to FIFO
    sleep(5); // Wait for 5 seconds

    // Open FIFO for writing
    int fd = open(fifo_name, O_WRONLY);
    
    // Write a message to FIFO
    char *message = "Hello from the writer!\n";
    write(fd, message, strlen(message) + 1);
    printf("Writer: Sent message: %s", message);
    
    // Close FIFO
    close(fd);
    
    return 0;
}

