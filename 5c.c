/* name - 5c
 author : Tathagata Das
 Description - number of clock ticks (jiffy) per second.
Date - 20th sept 2024
*/
#include <stdio.h>
#include <unistd.h>

int main() {
	long ticks_per_second = sysconf(_SC_CLK_TCK);
	if(ticks_per_second == -1){
		perror("sysconf");
		return 1;
	}
		
	printf("Number of clock ticks (jiffies) per second: %ld\n",ticks_per_second);
}
