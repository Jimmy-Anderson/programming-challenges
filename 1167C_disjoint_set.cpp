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
int *a,n;//Array as the disjoint data type

void makeset(int n)
{
	a=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		*(a+i)=-1;
	}
}
int findset(int x)
{
	if(a[x]<0)
		return x;
	else
	{
		a[x]=findset(a[x]);
		return a[x];
	}
}
int unionset(int x, int y)
{
	x=findset(x);
	y=findset(y);
	if(x!=y)
	{
		if(a[x]<a[y])
		{
			a[x]+=a[y];
			a[y]=x;
		}
		else if(a[x]>a[y])
		{
			a[y]+=a[x];
			a[x]=y;
		}
		else if(a[x]==a[y])
		{
			a[x]+=a[y];
			a[y]=x;
		}	
		return 1;
	}
	else
		return 0;
} 

int main()
{
	fastio
	int n,m;
	cin>>n>>m;
	makeset(n+1);
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
			int x=unionset(src,dest);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x=findset(i);
		cout<<a[x]*-1<<" ";
	}
}
