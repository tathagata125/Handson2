/* name - 5a
 author : Tathagata Das
 Description - Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
Date - 20th sept 2024
*/
#include<stdio.h>
#include<unistd.h>

int main(){
	long arg_max = sysconf(_SC_ARG_MAX);

	if(arg_max == -1){
		perror("sysconf");
		return 1;
	}

	printf("Maximum length of the arguments to the exec family of functions: %ld bytes\n", arg_max);
	
}
