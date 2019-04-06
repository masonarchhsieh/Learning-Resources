#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* next;
};
struct Node* head; //global
void Insert(int x){
	struct Node* temp = malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = head; 
	head = temp;
}
void Delete(int n) //delete node at position n
{
		struct Node* temp1 = head;
		if(n==1){
				head = temp1->next; 	//head now points to second node
				free(temp1);
				return;
		}
		int i;
		for (i=0; i<n-2; i++){
			temp1 = temp1->next;    	//temp1 points to (n-1)th Node
		}
		struct Node* temp2 = temp1->next;  //nth Node
		temp1->next = temp2->next; 		//(n+1)th Node
		free(temp2); 					//delete temp2'
}

void Print(){
	struct Node* temp = head;
	printf("list is: ");
	while(temp != NULL){
		printf(" %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);//list:2,4,6,5
	Print();
	int n;
	printf("enter a position \n");
	scanf("%d",&n);
	Delete(n);
	Print();

}
