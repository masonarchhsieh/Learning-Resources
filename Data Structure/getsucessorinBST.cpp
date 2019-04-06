#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

//function to find Node with minimum value in BST
struct Node* FindMin(struct Node* root){
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}


//function to find successor
struct Node* Getsuccessor(struct Node* root,int data){
	//search the node - O(h)
	struct Node* current = Find(root,data);
	if(current == NULL) return NULL;
	//case1: Node has right subtree
	if(current->right != NULL){
		return FindMin(current->right);	//O(h)
	}
	//case2: no right subtree - O(h)
	else{
		struct Node* successor = NULL;
		struct Node* ancestor = root;
		while(ancestor != current){
			if(current->data < ancestor->data){
				successor = ancestor;	//so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
