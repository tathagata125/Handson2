/* name - 5g
 author : Tathagata Das
 Description - number of currently available pages in the physical memory.
Date - 20th sept 2024
*/
#include <unistd.h>
#include <sys/sysinfo.h>
#include <stdio.h>
int main() {
	struct sysinfo info;
	
	if(sysinfo(&info) != 0 ) {
		perror("sysinfo");
		return 1;
	}
	
	long page_size = sysconf(_SC_PAGESIZE);
	if(page_size == -1) {
		perror("sysconf");
		return 1;
	}
	
	unsigned long available_pages = info.freeram/page_size;

	printf("Number of currently available pages in physical memory: %lu\n", available_pages);
}
