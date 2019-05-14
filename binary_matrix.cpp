#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    cin.ignore(256, '\n');
   // int mat[n][m];
    vector<vector<int>>mat;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        vector<int>pic;
        for(int j=0;j<m;j++)
            pic.push_back((int)(str[j]-'0'));
        mat.push_back(pic);
    }
    set<int>s;
    int j,flag=0;
    for(j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(mat[i][j]==1)
                flag=1;
        }
        if(flag==1)
            break;
    }
    for(int i=0;i<n;i++)
        if(mat[i][j]==1)
            s.insert(i);
    j++;
    set<int>::iterator itr;
    while(s.size()!=1&&j<m)
    {
        for(itr=s.begin();itr!=s.end();itr++)
        {
            if(mat[(*itr)][j]==0)
                int num=s.erase((*itr));
        }
        j++;
    }
    vector<int>a;
    if(s.size()==0)
        cout<<"0\n";
    else
    {
       for(itr=s.begin();itr!=s.end()&&s.size()!=0;itr++)
        a.push_back((*itr));
        cout<<a[0]+1<<"\n";
    }

}
