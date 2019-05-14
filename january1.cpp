#include<bits/stdc++.h>
#define lli long long int
#define for(a,b,c) for(int i=a;i<b;i+=c)
#define test() int t;	cin>>t;	while(t--)
#define mod 1000000007
using namespace std;
int main()
{
	lli n;
	cin>>n;
	lli a[n],b[n];
	for(0,n,1)
		cin>>a[i];
	for(0,n,1)
		cin>>b[i];
	sort(a,a+n);	
	sort(b,b+n);
	lli sum=0;
	for(0,n,1)
	{
		lli diff=abs(a[i]-b[i]);
		sum+=diff%mod;
	}	
		cout<<sum%mod<<"\n";
}