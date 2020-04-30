#include<iostream>
#include<stdlib.h>

using namespace std;

class BTreeNode{
    int *keys;//Array of keys
    int t;// Maximum keys= 2t-1, Minimum keys=t-1, Maximum children=2t 
    BTreeNode **C;//Array of children
    int n;//Current number of keys
    bool leaf;
    BTreeNode(int _t,bool leaf);

    // Functions to search and traverse
    void traverse();
    BTreeNode *search(int k);

    // Functions to insert new node
    void insertNonFull(int k);
    void splitChild(int i,BTreeNode *y);


    friend class BTree;
};

class BTree{
    BTreeNode *root;
    int t;

public:
    BTree(int degree){
        root=NULL;
        t=degree;
    }
    
    // Function to traverse the tree
    void traverse(){
        if(root){//If root is not null
            root->traverse();
        }
    }

    // Function to search the tree
    BTreeNode * search(int k){
        return (root==NULL)?NULL: root->search(k);
    }

    //Function to insert a new node
    void insert(int k);

};

BTreeNode :: BTreeNode(int degree,bool isLeaf){
    t=degree;
    leaf=isLeaf;

    keys= new int[2*t-1];
    C = new BTreeNode* [2*t];
    n=0;
}

void BTreeNode::traverse(){
    int i=0;
    // There are n keys and n+1 children

    for(i=0; i<n;i++){
        //If this is not leaf, traverse the 
        // subtree rooted with child i before printing key i
        if(leaf==false)
            C[i]->traverse();
        cout<<" "<<keys[i];
    }
    if(leaf==false)
        C[i]->traverse();
}

BTreeNode *BTreeNode::search(int k){
    int i=0;
    while(i<n&&k>keys[i])
        i++;
    
    if(keys[i]==k)
        return this;
    
    if(leaf==true)
        return NULL;

    return C[i]->search(k);
}

void BTree::insert(int k){
    if(!root){
        root=new BTreeNode(t,true);
        root->keys[0]=k;
        root->n=1;
        return;
    }
    if(root->n == 2*t-1)//root is full
    {
        BTreeNode *x= new BTreeNode(t,false);
        //Make old root as child of new root
        x->C[0]=root;
        //Split the old root and move 1 key to the new root
        x->splitChild(0,root);
        // New root has two children now
        // Decide which of the two children is going to have the new key
        int i=0;
        if(x->keys[0]<k)
            i++;
        //Insert the new node in appropriate child
        x->C[i]->insertNonFull(k);
        root=x;
    }
    else//root is not full
        root->insertNonFull(k);

}

// Function to split child y of the node x which is full for insertion

void BTreeNode :: splitChild(int i, BTreeNode * y)
{    
    // Create a node which is going to store last t-1 keys of y
    BTreeNode *z= new BTreeNode(y->t,y->leaf);
    z->n=t-1;

    for(int j=0;j<t-1;j++)
        z->keys[j] = y->keys[j+t];
    if(y->leaf==false)
    {
        for(int j=0;j<t;j++){
            z->C[j]= y->C[j+t];
        }
    }

    y->n=t-1;

    //Since the current node is going to have another child
    //create space for new child
    //n is the number of children currently present
    for(int j=n;j>=i+1;j--)
        C[j+1]=C[j];
    
    // Link the new child to this node
    C[i+1]=z;

    //Move one key of y to this node
    //Find location of new key and move all keys i step ahead
    for(int j=n-1;j>=i;j--)
        keys[j+1]=keys[j];
    
    // Copy the middle key of y to this node
    keys[i] = y->keys[t-1];
    n=n+1;    
}

//Function to insert key a non full node
void BTreeNode::insertNonFull(int k){
    //Initialize index as index of rightmost element
    int i=n-1;

    if(leaf==true){
        //Move all keys greater than k one place ahead
        while(i>=0&&keys[i]>k){
            keys[i+1]=keys[i];
            i--;
        }
        keys[i+1]=k;
        n=n+1;
    }
    else//If this node is not leaf
    {
        //Move all keys greater than k one place ahead
        while(i>=0 && keys[i]>k)
            i--;
        
        // See if child found is full
        if(C[i+1]->n == 2*t-1)
        {
            // If child is full,split it
            splitChild(i+1,C[i+1]);

            // After split, the middle key of C[i] goes up and 
            // C[i] is splitted into two.  See which of the two 
            // is going to have the new key 
            if (keys[i+1] < k) 
                i++;
            C[i+1]->insertNonFull(k); 
        }
    }

}

int main(){
    int c=1,data;
    int degree;
    cout<<"\nEnter the degree of tree(t)\n";
    cin>>degree;
    BTree root(degree);
    while(c){
        cout<<"Enter your choice 1. Insert 2. Delete 3.search 4.DFS 0.exit\n";
        cin>>c;
        if(!c)
            break;
        if(c==1)
        {
            cout<<"Enter data to insert\n";
            cin>>data;
            root.insert(data);
        }
        else if(c==2){
            cout<<"Enter value to delete\n";
            cin>>data;
            // root=deleteNode(root,data);
        }
        else if(c==3){
            cout<<"Enter data to search\n";
            cin>>data;
            cout<<(root.search(data)?"Yes it is found\n":"No, its not found\n");
        }
        else if(c==4)
        {
            root.traverse();
            cout<<endl;
        }
           
    }
}