#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
vector<int>adj[500001];
vector<int>visited(500001,0);
int count;
void dfs(int n)
{
    ::count++;
	visited[n]=1;
	for(int i=0;i<adj[n].size();i++)
		if(!visited[adj[n][i]])
			dfs(adj[n][i]);
}
int main()
{
	fastio
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int ki;
		cin>>ki;
		if(!ki)
			continue;
		int src;
		cin>>src;
		ki--;
		while(ki--)
		{
			int dest;
			cin>>dest;
			adj[src].push_back(dest);
			adj[dest].push_back(src);
		}
	}
	for(int i=1;i<=n;i++)
	{
	    ::count=0;
	     memset(&visited[0], 0, 500001 * sizeof(visited[0]));//500001=visited.size()
        dfs(i);
		cout<<::count<<" ";
	}
}
