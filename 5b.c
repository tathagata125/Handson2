/* name - 5b
 author : Tathagata Das
 Description - maximum number of simultaneous process per user id.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
	struct rlimit r1;
	//Get the resource limit for the maximum number of processes per user ID
	if(getrlimit(RLIMIT_NPROC, &r1) == -1){
		perror("getrlimit");
		return EXIT_FAILURE;
	}
	printf("Maximum number of simultaneous processes per user ID: \n");
	printf("Soft limit: %ld\n", r1.rlim_cur);
	printf("Hard limit: %ld\n", r1.rlim_max);

	return EXIT_SUCCESS;
}
