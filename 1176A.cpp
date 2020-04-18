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
		int count2=0,count3=0,count5=0;
		while(n%2==0)
		{
			count2++;
			n/=2;
		}
		while(n%3==0)
		{
			count3++;
			n/=3;
		}
		while(n%5==0)
		{
			count5++;
			n/=5;
		}
		int ans=0;
		if(n==1)
			ans=count2+2*count3+3*count5;
		else
			ans=-1;
		cout<<ans<<"\n";
	}
}