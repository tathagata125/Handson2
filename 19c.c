/* name - 19c
 author : Tathagata Das
 Create a FIFO file by
use strace command to find out, which command (mknod or mkfifo) is better.
   Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create FIFO using mkfifo with strace
    printf("Creating FIFO using mkfifo:\n");
    system("strace mkfifo myfifo 2> mkfifo_strace.txt");
    
    // Create FIFO using mknod with strace
    printf("\nCreating FIFO using mknod:\n");
    system("strace mknod myfifo p 2> mknod_strace.txt");

    
    printf("\nOutput of strace for mkfifo is saved in mkfifo_strace.txt\n");
    printf("Output of strace for mknod is saved in mknod_strace.txt\n");

    return 0;
}

