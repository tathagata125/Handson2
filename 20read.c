/* name - 20
 author : Tathagata Das
Write two programs so that both can communicate by FIFO -Use one way communication.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo";
    char buffer[100];
    
    // Open the FIFO for reading
    int fd = open(fifo_name, O_RDONLY);
    
    // Read a message from the FIFO
    read(fd, buffer, sizeof(buffer));
    printf("Reader: Received message: %s", buffer);
    
    // Close the FIFO
    close(fd);
    
    // Optionally, remove the FIFO
    unlink(fifo_name);

    return 0;
}

