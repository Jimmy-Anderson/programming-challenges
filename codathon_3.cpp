#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define test() int t;	cin>>t;	while(t--)
using namespace std;
int main()
{
	test()
	{
		lli t0,t1,t2,y;
		cin>>t0>>t1>>t2>>y;
		lli a[4];
		a[0]=t0%mod;
		a[1]=t1%mod;
		a[2]=t2%mod;
		for(lli i=3;i<=y;i++)
		{
			a[3]=a[2]%mod+(3*a[0]%mod)%mod+(2*i)%mod;
			a[0]=a[1];
			a[1]=a[2];
			a[2]=a[3];
		}
		if(y==1)
			cout<<t1%mod<<"\n";
		else if(y==2)
			cout<<t2%mod<<"\n";
		else
			cout<<a[3]%mod<<"\n";
	}
	return 0;
}