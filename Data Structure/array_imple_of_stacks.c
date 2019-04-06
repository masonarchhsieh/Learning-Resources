#include <stdio.h>
#define Max_size 101

int A[Max_size];
int top = -1;

void Push(int x){

	if(top == Max_size -1){
		printf("error: stack overflow \n");
		return;
	}

	top++;
	A[top] = x;
	//== A[++top] = x;
}

void Pop(){
	if(top == -1){
		printf("error: no element to pop \n");
		return;
	}
	top--;
}

int Top(){
	return A[top];
}

void Print(){
	int i;
	printf("stack: ");
	for(i=0; i<=top; i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main(){
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();

}
