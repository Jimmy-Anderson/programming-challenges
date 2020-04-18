#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node{
	int income;
	struct Node *left;
	struct Node *right;
	int count;
}node;


node* newnode(int income,int count){
	node* x= (node*)malloc(sizeof(node));
	x->income=income;
	x->count=count;
	x->left=NULL;
	x->right=NULL; 
}
node* insert(node *root,int income,int count){
	if(root==NULL){
		root=newnode(income,count);
	}
	else if(root->income>income){
		root->left=insert(root->left,income,count);
	}
	else if(root->income<income){
		root->right=insert(root->right,income,count);
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
node* deleteNode(node *root,int income){
	if(root==NULL)
		return root;
	if(income<root->income)
		root->left=deleteNode(root->left,income);
	else if(income>root->income)
		root->right=deleteNode(root->right,income);
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
			root->income=inorderSuccesor->income;
			deleteNode(root->right,inorderSuccesor->income);
		}
	}
}
bool search(node *root,int income){
	if(!root)
		return false;
	if(root->income==income)
		return true;
	else if(root->income<income)
		return search(root->right,income);
	else
		return search(root->left,income);
}

void constructTree(node** root)
{
	FILE *myFile;
    myFile = fopen("in.txt", "r");
	

    if (myFile == NULL){
        printf("Error Reading File in.txt\n");
        exit (0);
    }
    int size;
    fscanf(myFile, "%d \n", &size );
    for (int i = 0; i < size; i++){
    	int income,count;
        fscanf(myFile, "%d %d\n", &income,&count );
        (*root)=insert((*root),income,count);
    }
    fclose(myFile) ;
}
void inorder(node *root,FILE *outFile){
	if(!root)
		return;
	inorder(root->left,outFile);
	fprintf(outFile," (%d,%d),",root->income,root->count);
	inorder(root->right,outFile);
}
int countNodes(node *root){
	if(!root)
		return 0;
	return 1+countNodes(root->left)+countNodes(root->right);
}
int totalIncome(node *root){
	if(!root)
		return 0;
	return root->income+totalIncome(root->left)+totalIncome(root->right);
}
node * highestIncome(node* root){
	node *cur=root;
	while(cur->right)
		cur=cur->right;
	return cur;
}
int main(){
	node* root=NULL;
	constructTree(&root);

	FILE *outFile;
    outFile = fopen("out.txt", "w");
    if (outFile == NULL){
        printf("Error Reading File out.txt\n");
        exit (0);
    }

    fprintf(outFile, "Tree constructed from the file:\n");
    fprintf(outFile, "Inorder:");
    inorder(root,outFile);
    fprintf(outFile, "\nHighest Income: %d Total people with highest income: %d\n",highestIncome(root)->income,highestIncome(root)->count);
    fprintf(outFile, "Total number of single children in the tree: %d\n",countNodes(root)) ;
    fprintf(outFile, "Total income in the area: %d\n",totalIncome(root)) ;


    
    fclose(outFile) ;
}