#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct node{
    int data;
    int height;
    struct node* left;
    struct node* right;
}node;
node* newnode(int data){
    node *x=(node*)malloc(sizeof(node));
    x->data=data;
    x->left=x->right=NULL;
    x->height=1;
}
int height(node*root){
    if(!root)
        return 0;
    return root->height;
}
int getBalanceFactor(node *root){
    if(!root)
        return 0;
    return height(root->left)-height(root->right);
}
node* rightRotate(node *x){
    node *y,*T2,*z;
    y=x->left;
    T2=y->right;
    y->right=x;
    x->left=T2;
    return y;
}
node* leftRotate(node *x){
    node *y,*T2,*z;
    y=x->right;
    T2=y->left;
    y->left=x;
    x->right=T2;
    return y;
}
node* insert(node *root, int data){
    if(!root)
        return newnode(data);
    if(root->data<data)
        root->right=insert(root->right,data);
    else if(root->data>data)
        root->left=insert(root->left,data);
    else 
        return root;
    root->height=1+max(height(root->left),height(root->right));

    int balance=getBalanceFactor(root);

    if(balance>1&&data<root->left->data)
        return rightRotate(root);
    else if(balance>1&&data>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance<-1&&data>root->right->data)
        return leftRotate(root);
    else if(balance<-1&&data<root->right->data){
        root->right=rightRotate(root->left);
        return leftRotate(root);
    }
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
    }
    else{
        if(!root->left||!root->right){
            node *temp=root->left?root->left:root->right;
            if(!temp){
                temp=root;
                root=NULL;
            }
            else{
                root=temp;
            }
            free(temp);
        }
        else{
            node *nextGreater=root->right;
            while(nextGreater->left)
                nextGreater=nextGreater->left;
            root->data=nextGreater->data;
            root->right=deleteNode(root->right,nextGreater->data);
        }

    }
    if(!root)
        return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalanceFactor(root);

    if(balance>1 && getBalanceFactor(root->left)>=0)
        return rightRotate(root);
    else if(balance>1 && getBalanceFactor(root->left)<0){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance<-1 && getBalanceFactor(root->right)<=0)
        return leftRotate(root);
    else if(balance<-1&&getBalanceFactor(root->right)>0){
        root->right=rightRotate(root->left);
        return leftRotate(root);
    }
    return root;

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
        cout<<"Enter your choice 1. Insert 2. Delete 3.search 4.preorder 0.exit\n";
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