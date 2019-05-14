#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
	lli n;
	cin>>n;
	lli a[n]={0};
	lli increment[n]={0};
	int m;
	cin>>m;
	lli max=0;
	while(m--)
	{
		lli a,b,k;
		cin>>a>>b>>k;
		increment[a]+=k;
		if(increment[a]>max)
			max=increment[a];
		if(b<n)
			increment-=k;
	}
	cout<<max<<"\n";
	
}