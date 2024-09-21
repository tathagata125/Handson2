/* name - 5f
 author : Tathagata Das
 Description - total number of pages in the physical memory
Date - 20th sept 2024
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
	struct sysinfo info;

	if(sysinfo(&info) != 0) {
		perror("sysinfo");
		return 1;
	}
	
	long page_size = sysconf(_SC_PAGESIZE);
	if(page_size == -1){
		perror("sysconf");
		return 1;
	}

	unsigned long total_pages = info.totalram / page_size;
	printf("Total number of pages in physical memory: %lu\n",total_pages);

}
