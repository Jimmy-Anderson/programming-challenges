#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
int  check_matrix_equal(vector<string> &A,vector<string> &B,int row,int col)
{
    int flag=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(A[i][j]!=B[i][j])
                flag=0;
        }
    }
    return flag;
}
string gridSearch(vector<string> G, vector<string> P) {
    int rg,cg,rp,cp;
    rg=G.size();
    cg=G[0].size();
    rp=P.size();
    cp=P[0].size();
    int flag=0;
    for(int i=0;i<=rg-rp;i++)
    {
        for(int j=0;j<=cg-cp;j++)
        {
            vector<string>submatrix;
            for(int k=i;k<i+rp;k++)
                submatrix.push_back(G[k].substr(j,cp));
            int f=check_matrix_equal(submatrix,P,rp,cp);
            if(f==1)
                flag=1;
        }
    }
    if(flag==1)
        return "YES";
    else
        return "NO";

}

int main()
{
    int rg,cg,rp,cp;
    int t;
    cin>>t;
    while(t--)
    {
        vector<string> G,P;
        cin>>rg>>cg;
        for(int i=0;i<rg;i++)
        {
            string s;
            cin>>s;
            G.push_back(s);
        }
        cin>>rp>>cp;
        for(int i=0;i<rp;i++)
        {
            string s;
            cin>>s;
            P.push_back(s);
        }
        cout<<"hello\n";
        cout<<gridSearch(G,P)<<"\n";
    }
}
