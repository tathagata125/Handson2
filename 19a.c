/* name - 19a
 author : Tathagata Das
 Create a FIFO file by
a. mknod command
Date - 20th sept 2024
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    const char *fifo_name = "myfifo";

    // Create the FIFO using mknod
    if (mknod(fifo_name, S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO '%s' created successfully.\n", fifo_name);

    return 0;
}

