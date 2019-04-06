#include <iostream>
#include <stack>  	//stack from standard template library(STL)
#include <vector>
#include <string>
#include <ctype.h>
#include <string.h>
using namespace std;

/*
class stack{
private:
	char A[101];
	int top;
public:
	void Push(int x);
	void Pop();
	int Top();
	bool IsEmpty();
};

*/

void Reverse(char *C,int n){
	vector<char> S;
	//loop for Push
	for(int i=0; i<n; i++){
		S.push_back(C[i]);
	}
	//loop for Pop
	for(int i=0; i<n; i++){
		C[i] = S.end();	//overwrite the character at index 1
		S.pop_back();  	//perform pop
	}

}


int main(){
	char C[51];
	printf("enter a string");
	cin.getline(C,51);
	Reverse(C,strlen(C));
	printf("Output = %s",C);


}


/* Reverse a Linked List

void Reverse(){
	if(head == NULL) return;
	stack<struct Node*> S;
	Node* temp = head;
	while(temp != NULL){
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top(); head = temp;
	S.pop();
	while(!S.empty()){
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}	*/
