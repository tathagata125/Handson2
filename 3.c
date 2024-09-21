/* name - 3
 author : Tathagata Das
 Description - 3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
int main() {
	struct rlimit r1;
	if(getrlimit(RLIMIT_NOFILE, &r1) == 0)//RLIMIT_NOFILE this is the specific resource limit that controls how many file descriptors a sngle process can have open simultaneously
	{
		printf("soft limit: %ld\n", r1.rlim_cur);
		printf("hard limit: %ld\n", r1.rlim_max);
	}
	r1.rlim_cur = 1024;
	r1.rlim_max = 2048;
	
	if(setrlimit(RLIMIT_NOFILE, &r1) == -1){
		perror("setrlimit");
		exit(EXIT_FAILURE);
	}
	printf("soft limit: %ld\n", r1.rlim_cur);
	printf("hard limit: %ld\n", r1.rlim_max);
}
