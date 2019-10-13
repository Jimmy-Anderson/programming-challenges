#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
    vector<string>A;
    int n;
    cin>>n;
    rep(i,1,n)
    {
        string s;
        cin>>s;
        A.push_back(s);
    }
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(A[i].size()<min)
            min=A[i].size();
    }
    string s="";
    for(int i=0;i<min;i++)
    {
        char ch=A[0][i];
        int j;
        for(j=1;j<n;j++)
        {
            if(A[j][i]!=ch)
                break;
        }
        if(j==n)
        {
            s.push_back(ch);
        }
    }
    cout<<s<<"\n";
}
