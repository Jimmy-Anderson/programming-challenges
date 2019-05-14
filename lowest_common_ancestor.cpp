#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    Node *lca(Node *root, int v1,int v2) {
		vector<int>n1;
        vector<int>n2;
        Node *temp=root;
        while(temp)
        {
            if(v1<temp->data)
            {
                n1.push_back(temp->data);
                temp=temp->left;
            }
            else if(v1>temp->data)
            {
                n1.push_back(temp->data);
                temp=temp->right;
            }
            else
            {
                n1.push_back(temp->data);
                break;
            }
        }
        temp=root;
        while(temp)
        {
            if(v2<temp->data)
            {
                n2.push_back(temp->data);
                temp=temp->left;
            }
            else if(v2>temp->data)
            {
                n2.push_back(temp->data);
                temp=temp->right;
            }
            else
            {
                n2.push_back(temp->data);
                break;
            }
        }
        int i,j;
        int lca;
        for(i=0;i<n1.size();i++)
        {
            for(j=0;j<n2.size();j++)
            {
                if(n1[i]==n2[i])
                    lca=n1[i];
            }
        }
        temp=root;
        while(temp)
        {
            if(lca<temp->data)
                temp=temp->left;
            else if(lca>temp->data)
                temp=temp->right;
            else
                break;
        }
        return temp;
    }

}; //End of Solution