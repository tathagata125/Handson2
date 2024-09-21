/* name - 4
 author : Tathagata Das
 Description - Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date - 20th sept 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<stdint.h>
static inline uint64_t rdtsc() {
	unsigned int lo, hi;
	__asm__ volatile ("rdtsc" : "=a" (lo), "=d" (hi));//"=a"(lo) : this specifies that the lower 32 bits of the TSC result will be stored in the EAX register , which is mapped to the lo variable in cand "=d" (hi): this specifies that the upper 32 bits of the TSC result will be stored in the EDX register , which is mapped to the hi variable in c
	return ((uint64_t)hi << 32) | lo;
}

int main() {
	uint64_t start, end;
	int i;
	start = rdtsc();
	
	for(i=0; i<100; i++){
		getpid();
	}
	
	end = rdtsc();

	printf("cpu cycles taken for 100 getppid() calls: %lu\n", (end-start));
}
