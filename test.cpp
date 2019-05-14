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
	test()
	{
		lli n;
		cin>>n;
		lli b[3];
		b[0]=1;
		b[1]=3;
		for(int i=3;i<=n;i++)
		{
			b[2]=2*b[1]-b[0]+1;
			b[0]=b[1];
			b[1]=b[2];
		}
		cout<<b[2]<<"\n";
	}	
}