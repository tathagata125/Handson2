/* name - 5d
 author : Tathagata Das
 Description - maximum number of open files
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    struct rlimit rl;

    // Get the resource limit for the maximum number of open files
    if (getrlimit(RLIMIT_NOFILE, &rl) == -1) {
        perror("getrlimit");
        return EXIT_FAILURE;
    }

    // Print the maximum number of open files
    printf("Maximum number of open files:\n");
    printf("  Soft limit: %ld\n", rl.rlim_cur);
    printf("  Hard limit: %ld\n", rl.rlim_max);

    return EXIT_SUCCESS;
}
