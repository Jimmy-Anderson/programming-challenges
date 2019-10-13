#include<bits/stdc++.h>
#include<string>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

// int digsum(lli n)
// {
// 	int sum=0;
// 	while(n>0)
// 	{
// 		sum+=n%10;
// 		n/=10;
// 	}
// 	return sum;
// }
int main()
{
	// vector<lli>v;
	// v.push_back(0);
	// for(lli i=1;i<=10000000000000000;i++)
	// {
	// 	if(digsum(i)%10==0)
	// 		v.push_back(i);
	// }
	test()
	{
		lli n;
		cin>>n;
		stringstream ss;
		ss<<n;
		string ans=ss.str();
		lli digsum=0;
		lli a=n;
		while(a>0)
		{
			digsum+=(a%10);
			a/=10;
		}
		lli last_digit=0;
		for(lli i=0;i<=9;i++)
		{
			if(((digsum+i)%10)==0)
			{
				last_digit=i;
				break;
			}
		}
		ans=ans+to_string(last_digit);
		cout<<ans<<"\n";
	}
	
}