#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
    lli n,m,k,w;
    cin>>n>>m>>k>>w;
    map<pair<int,int>,lli>val;
    rep(i,0,k){
        lli x,y,v;
        cin>>x>>y>>v;
        val[{x,y}]=v;
    }
    lli x=1,y=1,count=0;
    lli danger=100000007700000049;
    queue<pair<lli,lli>>q;
    if(val[{x,y}]==danger){
        cout<<count<<"\n";
        exit(0);
    }
    q.push({x,y});
    while(!q.empty()){
        pair<lli,lli> top=q.front();
        q.pop();
        x=top.first;
        y=top.second;
        if(x==n && y==m)
            count++;
        if(x+1<=n&&val[{x+1,y}]!=danger)
            q.push({x+1,y});
        if(y+1<=m&&val[{x,y+1}]!=danger)
            q.push({x,y+1});
    }
    cout<<count<<"\n";
}