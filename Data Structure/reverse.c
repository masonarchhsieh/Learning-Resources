#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* next;
};

void Print(struct Node* p){
//	if(p == NULL) return;   //Exit condition
	if(p == NULL){
		printf("\n");
		return;
	}
	printf("%d ",p->data);		//First print the value in the node
	Print(p->next);			//Recursive call
}

struct Node* Insert(Node *head, int data){
	Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL) head = temp;
	else{
		Node* temp1 = head;
		while(temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

int main(){
	struct Node* head = NULL;     //local variable
	head = Insert(head,2);
	head = Insert(head,4);
	head = Insert(head,6);
	head = Insert(head,5);
	Print(head);
}
