#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
	temp->data = x;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}


void Dequeue(){
	struct Node* temp = front;
	if(front == NULL)	return;
	if(front == rear){
		front = rear = NULL;
	}
	else{
		front = front->next;
	}
	free(temp);
}


