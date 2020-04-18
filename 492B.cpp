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
	int n;
	cin>>n;
	int arr[3];
	for(int i=0;i<3;i++)
		cin>>arr[i];
	int dp[n+1];
	for(int i=1;i<=n;i++)
		dp[i]=INT_MIN;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i>=arr[j])
			{
				int sub_res=dp[i-arr[j]];
				if(sub_res!=INT_MIN&&sub_res+1>dp[i])
					dp[i]=sub_res+1;	
			}
		}
	}
	cout<<dp[n]<<"\n";
}