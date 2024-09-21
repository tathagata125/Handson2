/* name - 1b
 author : Tathagata Das
 Description - Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
b. ITIMER_VIRTUAL
Date - 20th sept 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>

void handle_alarm(int signum){
	printf("Timer Expired(ITIMER_VIRTUAL)\n");
}
int main(){
	struct itimerval timer;
	signal(SIGVTALRM, handle_alarm);
	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 10;
	timer.it_interval.tv_sec = 10;
	timer.it_interval.tv_usec = 10;
if(setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1){
	perror("error in timer setting");
	exit(1);
}
	while(1){
	}
}
