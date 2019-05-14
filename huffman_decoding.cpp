

/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    string res="";
    node *cur=root;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')
            cur=cur->left;
        else
            cur=cur->right;
        if(cur->left==NULL&&cur->right==NULL)
        {
            res=res+cur->data;
            cur=root;
        }
    }
    //res=res+'\0';
    cout<<res;
}

