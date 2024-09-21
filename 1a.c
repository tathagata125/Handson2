/* name - 1a
 author : Tathagata Das
 Description - Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date - 20th sept 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>

void handle_alarm(int signum){
	printf("Timer Expired(ITIMER_REAL)\n");
}
int main()
{
	struct itimerval timer;
	signal(SIGALRM,handle_alarm);
	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 10;
	timer.it_interval.tv_sec = 10;
	timer.it_interval.tv_usec = 10;

	if(setitimer(ITIMER_REAL, &timer, NULL) == -1){
		perror("Error Setting timer");
	}
	while(1){
		pause();
	}
	
}
