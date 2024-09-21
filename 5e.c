/* name - 5e
 author : Tathagata Das
 Description - size of a page
Date - 20th sept 2024
*/
#include <stdio.h>
#include <unistd.h>

int main() {
	long page_size = sysconf(_SC_PAGESIZE);
	
	if(page_size == -1){
		perror("sysconf");
		return 1;
	}
	
	
	printf("Size of a memory page: %ld bytes\n", page_size);
	
}
