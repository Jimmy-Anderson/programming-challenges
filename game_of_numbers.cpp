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
	fastio
	lli n;
	cin>>n;
	lli a[n];
	rep(0,n,1)
		cin>>a[i];
	stack<lli>greater;
	stack<lli>greateri;
	stack<lli>smaller;
	stack<lli>smalleri;
	lli g[n]={0};
	lli l[n]={0};
	repd(n-1,0,1)
	{
		while(!greater.empty()&&greater.top()<=a[i])
		{
			greater.pop();
			greateri.pop();
		}
		if(greater.empty())
			g[i]=-1;
		else
			g[i]=greateri.top();
		greater.push(a[i]);
		greateri.push(i);
		while(!smaller.empty()&&smaller.top()>=a[i])
		{
			smaller.pop();
			smalleri.pop();
		}
		if(smaller.empty())
			l[i]=-1;
		else
			l[i]=smalleri.top();
		smaller.push(a[i]);
		smalleri.push(i);
	}
	lli ans[n];
	rep(0,n,1)
	{
		if(g[i]==-1)
			ans[i]=-1;
		else if(l[g[i]]==-1)
			ans[i]==-1;
		else
			ans[i]=a[l[g[i]]];
	}
	rep(0,n,1)
		cout<<ans[i]<<" ";
}