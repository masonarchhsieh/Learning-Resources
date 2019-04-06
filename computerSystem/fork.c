#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//compie with: gcc -Wall -Werror -o fork fork.c
int main(){
	int x=1;

	if(fork() == 0){
		//Only child process executes this 
		printf("child,x=%d\n",++x);
	}
	else{
		//only parent executes this
		printf("parent,x=%d\n",--x);

	}
	printf("exiting with x=%d\n",x);
	return 0;
}
