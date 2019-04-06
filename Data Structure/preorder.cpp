#include <iostream>

using namespace std;

struct Node{
	char data;
	Node *left;
	Node *right;
};

void Preorder(Node *root){
	if(root == NULL) return;

	printf("%c ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node *root){
	if(root == NULL) return;

	Inorder(root->left);
	printf("%c ",root->data);
	Inorder(root->right);
}

void Postorder(Node *root){
	if(root == NULL) return;

	Postorder(root->left);
	Postorder(root->right);
	printf("%c ",root->data);
}
