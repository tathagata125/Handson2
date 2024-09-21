/* name - 19b
 author : Tathagata Das
 Create a FIFO file by
a. mkfifo command

 Date - 20th sept 2024  
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo";

    // Create the FIFO (named pipe)
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO '%s' created successfully.\n", fifo_name);

    return 0;
}

