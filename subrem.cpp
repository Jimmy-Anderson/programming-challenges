#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
vector< vector<lli> >adj;
vector<lli>visited;
lli a[100005],n,x;
lli dfs(lli s)
{
	visited[s]=1;
	lli z;
	z=a[s];
	for(lli i=0;i<adj[s].size();i++)
		if(!visited[adj[s][i]])
			z+=dfs(adj[s][i]);
	return max(-x,z);
}
int main()
{
	test()
	{
		lli u,v;
		cin>>n>>x;
		//initialize
		rep(i,0,n+1)
			adj.push_back(vector<lli>());
		rep(i,1,n+1)
			cin>>a[i];
		rep(i,1,n)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		rep(i,0,n+1)
			visited.push_back(0);
		cout<<dfs(1)<<"\n";
		rep(i,0,n+1)
			adj[i].clear();
		visited.clear();
	}
}