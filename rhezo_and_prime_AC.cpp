#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
lli prime[5001],dp[5001];
vector<int> v;
void sieve()
{
	for(int i=0;i<5001;i++)
		prime[i]=1;
	for(int i=2;i*i<=5001;i++)
	{
		if(prime[i]==1)
			for(int j=i*i;j<5001;j+=i)
				prime[j]=0;
	}
	for(int i=2;i<5001;i++)
		if(prime[i])
			v.push_back(i);
}
void solve()
{
	lli n;
	cin>>n;
	if(n==1)
	{
	    cout<<"0\n";
	    return;
	}
	lli i,j;
	vector<lli>pre(n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i];
	}
	for(int i=1;i<=n;i++)
		pre[i]+=pre[i-1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=0;j<v.size() && v[j]<=i;j++)
		{
			if(i==v[j])//If i is a prime number
				dp[i]=max(dp[i],pre[i]);
			else//If i is not a prime number pre[i]-pre[i-v[j]]is sum of elements of sub array of prime length
				dp[i]=max(dp[i],pre[i]-pre[i-v[j]]+dp[i-v[j]-1]);
		//dp[i-v[j]-1]is skipping one element between prime arrays
		//so that the sub arrays remain prime and do not join to form non-prime length arrays
		    
		}
	}
	cout<<dp[n]<<"\n";
}
int main()
{
	sieve();
	solve();
}