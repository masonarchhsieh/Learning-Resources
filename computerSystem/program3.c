#include <stdio.h>
#include <stdlib.h>


//
int main(){
	int pipeEnds1[2];
	int pipeEnds2[2];

	pipe(pipeEnds1);
	pipe(pipeEnds2);

	int returnValue = fork();
	if(returnValue == 0){
		childProcess1();
	}
}

