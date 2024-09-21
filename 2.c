* name - 2
 author : Tathagata Das
 Write a program to print the system resource limits. Use getrlimit system call.
 Date - 20th sep 2024
*/
#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>
#include <string.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;
    if (getrlimit(resource, &limit) == 0) {
        printf("%-20s Soft limit: %10ld, Hard limit: %10ld\n", name, limit.rlim_cur, limit.rlim_max);
    } else {
        printf("Error getting limit for %s: %s\n", name, strerror(errno));
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU Time");
    print_limit(RLIMIT_FSIZE, "File Size");
    print_limit(RLIMIT_DATA, "Data Segment Size");
    print_limit(RLIMIT_STACK, "Stack Size");
    print_limit(RLIMIT_CORE, "Core File Size");
    print_limit(RLIMIT_RSS, "Resident Set Size");
    print_limit(RLIMIT_NOFILE, "Number of File Descriptors");
    print_limit(RLIMIT_AS, "Address Space Size");
    print_limit(RLIMIT_NPROC, "Number of Processes");
    print_limit(RLIMIT_MEMLOCK, "Locked Memory");
    print_limit(RLIMIT_LOCKS, "File Locks");
    return 0;
}

