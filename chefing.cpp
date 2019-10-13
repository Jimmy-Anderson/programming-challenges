#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define mod_inv_2 500000004
using namespace std;
int main()
{
	test()
	{
		lli n,k;
		cin>>n>>k;
		lli a=k-1;
		lli d=n-1;
		lli terms=1+a/d;
		lli sum;
		sum=((terms%mod*((2*a)%mod-((terms-1)%mod*d%mod)%mod+mod)%mod)%mod*mod_inv_2)%mod;
		cout<<sum<<"\n";
	}	
}