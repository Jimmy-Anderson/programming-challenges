#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}node;

node* newnode(int data){
	node* x= (node*)malloc(sizeof(node));
	x->data=data;
	x->left=NULL;
	x->right=NULL; 
}
node* insert(node *root,int data){
	if(root==NULL){
		root=newnode(data);
	}
	else if(root->data>data){
		root->left=insert(root->left,data);
	}
	else if(root->data<data){
		root->right=insert(root->right,data);
	}
	return root;
}
node *findSuccessor(node *root){
	if(!root)
		return NULL;
	if(root->left)
		return findSuccessor(root->left);
	else
		return root;
}
node* deleteNode(node *root,int data){
	if(root==NULL)
		return root;
	if(data<root->data)
		root->left=deleteNode(root->left,data);
	else if(data>root->data)
		root->right=deleteNode(root->right,data);
	else{
		if(root->left==NULL&&root->right==NULL){
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			node *temp=root->left;
			free(root);
			return temp;
		}
		else{
			node * inorderSuccesor=findSuccessor(root);
			root->data=inorderSuccesor->data;
			deleteNode(root->right,inorderSuccesor->data);
		}
	}
}
bool search(node *root,int data){
	if(!root)
		return false;
	if(root->data==data)
		return true;
	else if(root->data<data)
		return search(root->right,data);
	else
		return search(root->left,data);
}
int main(){
	int c=1,data;
	node *root=NULL;
	while(c){
		cout<<"\nEnter 1 to insert,2 to delete, 3 to search in bst, 0 to exit\n";
		cin>>c;
		if(!c)
			break;
		if(c==1){
			cout<<"Enter data to insert:\n";
			cin>>data;
			root=insert(root,data);
		}
		else if(c==2){
			cout<<"Enter data to delete:\n";
			cin>>data;
			root=deleteNode(root,data);	
		}
		else if(c==3){
			cout<<"Enter data to search:\n";
			cin>>data;
			if(search(root,data))
				cout<<"\nData found!\n";
			else
				cout<<"\nData Not found!\n";
		}
	}
}