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
		lli n,k,x;
		cin>>n;
		vector<lli>arr(n,0);
		vector<lli>diff(n,0);
		vector<lli>xor_arr(n,0);
		lli initSum=0;
		for(lli i=0;i<n;i++)
		{
			cin>>arr[i];
			initSum+=arr[i];
		}
		cin>>k>>x;
		rep(i,0,n)
		{
			xor_arr[i]=arr[i]^x;
			diff[i]=xor_arr[i]-arr[i];
		}
		sort(diff.begin(),diff.end(),greater<lli>());
		lli net_diff=0;
		for(lli i=0;i<n-k;i+=k)
		{
			lli sum=0;
			for(lli j=i;j<i+k;j++)
				sum+=diff[j];
			if(sum<=0)
				break;
			else
				net_diff+=sum;
		}
		cout<<net_diff+initSum<<"\n";
	}	
}