/* name - 20
 author : Tathagata Das
Write two programs so that both can communicate by FIFO -Use one way communication.
Date - 20th sept 2024*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *fifo_name = "myfifo";
    char *message = "Hello from the writer!\n";
    
    
    mkfifo(fifo_name, 0666);
    
    
    int fd = open(fifo_name, O_WRONLY);
    
    
    write(fd, message, strlen(message) + 1);
    printf("Writer: Sent message: %s", message);
    
    // Close the FIFO
    close(fd);
    
    return 0;
}

