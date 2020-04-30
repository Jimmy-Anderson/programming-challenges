#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* newnode(int data){
    node *x=(node*)malloc(sizeof(node));
    x->data=data;
    x->left=x->right=NULL;
}
node* insert(node *root, int data){
    if(!root)
        return newnode(data);
    if(root->data<data)
        root->right=insert(root->right,data);
    else if(root->data>data)
        root->left=insert(root->left,data);
    return root;
}
node * deleteNode(node *root,int data){
    if(!root)
        return NULL;
    if(root->data!=data){
        if(root->data>data)
            root->left=deleteNode(root->left,data);
        else
            root->right=deleteNode(root->right,data);
        return root;
    }
    else{
        if(!root->left&&!root->right){
            free(root);
            return NULL;
        }
        else if(!root->left||!root->right){
            if(root->left){
                node *temp=root->left;
                free(root);
                return temp;
            }
            else if(root->right){
                node *temp=root->right;
                free(root);
                return temp;
            }
        }
        else{
            node *nextGreater=root->right;
            while(nextGreater->left)
                nextGreater=nextGreater->left;
            root->data=nextGreater->data;
            root->right=deleteNode(root->right,nextGreater->data);
            return root;
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
    else if(root->data>data)
        return search(root->left,data);
}
void preorder(node *root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int c=1,data;
    node *root=NULL;
    while(c){
        cout<<"Enter your choice 1. Insert 2. Delete 3.search 4. preorder 0.exit\n";
        cin>>c;
        if(!c)
            break;
        if(c==1)
        {
            cout<<"Enter data to insert\n";
            cin>>data;
            root=insert(root,data);
        }
        else if(c==2){
            cout<<"Enter value to delete\n";
            cin>>data;
            root=deleteNode(root,data);
        }
        else if(c==3){
            cout<<"Enter data to search\n";
            cin>>data;
            cout<<(search(root,data)?"Yes it is found\n":"No, its not found\n");
        }

        else if(c==4)
        {
            preorder(root);
            cout<<endl;
        }
        
        
    }
}