/* name - 1c
 author : Tathagata Das
 Description - Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
c. ITIMER_PROF
Date - 20th sept 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>
void handle_prof_alarm(int signum){
	printf("Timer Expired!(ITIMER_PROF)\n");
}
int main(){
	struct itimerval timer;
	signal(SIGPROF, handle_prof_alarm);
	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 10;
	
	timer.it_interval.tv_sec = 10;
	timer.it_interval.tv_usec = 10;

	if(setitimer(ITIMER_PROF,&timer,NULL) == -1){
		perror("Error setting timer");
		exit(1);
	}
	while(1){
	
	}
}
