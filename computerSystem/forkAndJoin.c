#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

//compile with gcc -Wall -Werror -o forkAndJoin forkAndJoin.c
int main(int ac,char *av[]){
	pid_t childPIDorZero = fork();
	if(childPIDorZero < 0){
		perror("fork()error");
		exit(-1);
	}
	if(childPIDorZero != 0){
		printf("I'm the parent%d, my child is %d\n",getpid(),childPIDorZero);
		wait(NULL);//wait for child process to join with this parent
	}else{
		printf("i'm the child%d, my parent is %d\n",getpid(),getppid());
		execl("/bin/echo","echo","hello, world",NULL);
	}
	return 0;

}
