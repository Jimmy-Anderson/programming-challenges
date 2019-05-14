#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

void prime_check(int n,vector<bool>&prime_set)
{
	rep(0,n,1)
		prime_set.push_back(true);
	for(int i=2;i*i<=n;i++)
	{
		if(prime_set[i]==true)
		{
			for(int j=i*i ; j<=n; j+=i)
				prime_set[j]=false;
		}
	}
}

// lli solve(int i,int j,lli dp[][5001])
// {
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     if(i==j)
//          dp[i][j]=a[i];
//     else if(prime_set[j-i+1])
//         dp[i][j]=a[j]+solve(i,j-1,dp);
//     else
//         dp[i][j]=max(solve(i+1,j,dp),solve(i,j-1,dp));
// }
int main()
{
    int n;
    cin>>n;
    vector <bool> prime_set;
    prime_check(5001,prime_set);
    lli a[100001];
    lli sum[100001];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sum[0]=a[0];
    for(int i=1;i<n;i++)
        sum[i]=a[i]+sum[i-1];
    lli dp[n][n];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j]=a[i];
            else if(prime_set[j-i+1])
            {
                if(i>0)
                    dp[i][j]=sum[j]-sum[i-1];
                else
                    dp[i][j]=sum[j];
            }
            else
            {
                if(i!=0)
                    dp[i][j]=max(sum[j]-sum[i],sum[j-1]-sum[i-1]);
                else
                    dp[i][j]=max(sum[j]-sum[i],sum[j-1]);
            }
        }
    }
    lli ans =0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(dp[i][j]>ans)
                ans=dp[i][j];
        }
    }
    cout<<ans<<"\n";

}
