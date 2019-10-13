#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
lli modular_exp(lli base,lli exp)
{
	lli res=1;
	base=base%mod;
	while(exp>0)
	{
		if(exp&1)
			res=(res*base)%mod;
		base=(base*base)%mod;
		exp=exp/2;
	}
	return res;
}
int main()
{
	test()
	{
		lli k;
		cin>>k;
		lli ans=(5*modular_exp(2,k))%mod;
		cout<<ans<<"\n";
	}
}