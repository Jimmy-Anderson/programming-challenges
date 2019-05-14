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
	test()
	{
		lli n;
		cin>>n;
		lli a[n];
		lli sum=1;
		for(lli i=0;i<n;i++)
		{
			cin>>a[i];
			sum =sum+a[i]-1;
		}
		cout<<sum<<"\n";

	}		
}