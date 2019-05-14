#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
vector< vector<int> >adj;
vector<lli>valr,modval,maxval;
  
// Returns sum of all root to leaf paths. 
// The first parameter is root  
// of current subtree, the second  
// parameter is value of the number formed  
// by nodes from root to this node  
int treePathsSumUtil(int root, lli val)  
{  
    // Base case  
   	if(adj[root].size()==0)
   	{
   		val+=valr[root];
   		lli mval=val%modval[root];
   		if(mval>maxval[root])
   			maxval[root]=mval;
   		return val;
   	}
  	for(int i=0;i<adj[root].size();i++)
  	{
  		return valr[root]+treePathsSumUtil(adj[root][i],val);
  	}
}  

int main()
{

	test()
	{
		int n,u,v;
		cin>>n;
		//initialize
		rep(i,0,n+1)
			adj.push_back(vector<int>());
		rep(i,1,n)
		{
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		rep(i,0,n)
		{
			lli num;
			cin>>num;
			valr.push_back(num);
		}
		rep(i,0,n)
		{
			lli num;
			cin>>num;
			modval.push_back(num);
		}
		rep(i,0,n)
			maxval.push_back(-1);
		treePathsSumUtil(1,0);
		rep(i,0,n)
			if(maxval[i]!=-1)
				cout<<maxval[i]<<" ";
		cout<<"\n";
	}
	
}