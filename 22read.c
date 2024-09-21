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
#include <sys/select.h>
#include <errno.h>

int main() {
    const char *fifo_name = "myfifo";
    char buffer[100];

    // Open FIFO for reading
    int fd = open(fifo_name, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Set up select
    fd_set read_fds;
    struct timeval timeout;

    // Initialize the set
    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    // Set timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Reader: Waiting for data in FIFO...\n");

    // Wait for data or timeout
    int result = select(fd + 1, &read_fds, NULL, NULL, &timeout);
    
    if (result == -1) {
        perror("select");
        close(fd);
        return EXIT_FAILURE;
    } else if (result == 0) {
        printf("Reader: Timeout occurred! No data in FIFO.\n");
    } else {
        // Data is available to read
        read(fd, buffer, sizeof(buffer));
        printf("Reader: Received message: %s", buffer);
    }

    // Close FIFO
    close(fd);
    unlink(fifo_name); // Clean up the FIFO

    return 0;
}

