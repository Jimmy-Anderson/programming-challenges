#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
lli exponentMod(int A, int B, int C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;

    // If B is even
    long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }

    // If B is odd
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }

    return (int)((y + C) % C);
}

lli count_n(int n,int digit,int dp[][10])
{
    if(dp[n][digit]!=-1)
      return dp[n][digit];
    if(n==0)
        dp[n][digit]=0;
    else if(n==1)
        dp[n][digit]=1;
    else
    {
        if(digit==0)
            dp[n][digit]=(count_n(n-1,2,dp)+count_n(n-1,3,dp)+count_n(n-1,5,dp)+count_n(n-1,7,dp))%mod;
        if(digit==1)
            dp[n][digit]=(count_n(n-1,1,dp)+count_n(n-1,2,dp)+count_n(n-1,4,dp)+count_n(n-1,6,dp))%mod;
        if(digit==2)
            dp[n][digit]=(count_n(n-1,0,dp)+count_n(n-1,1,dp)+count_n(n-1,3,dp)+count_n(n-1,5,dp)+count_n(n-1,9,dp))%mod;
        if(digit==3)
            dp[n][digit]=(count_n(n-1,0,dp)+count_n(n-1,2,dp)+count_n(n-1,4,dp)+count_n(n-1,8,dp))%mod;
        if(digit==4)
            dp[n][digit]=(count_n(n-1,1,dp)+count_n(n-1,3,dp)+count_n(n-1,7,dp)+count_n(n-1,9,dp))%mod;
        if(digit==5)
            dp[n][digit]=(count_n(n-1,0,dp)+count_n(n-1,2,dp)+count_n(n-1,6,dp)+count_n(n-1,8,dp))%mod;
        if(digit==6)
            dp[n][digit]=(count_n(n-1,1,dp)+count_n(n-1,5,dp)+count_n(n-1,7,dp))%mod;
        if(digit==7)
            dp[n][digit]=(count_n(n-1,0,dp)+count_n(n-1,4,dp)+count_n(n-1,6,dp))%mod;
        if(digit==8)
            dp[n][digit]=(count_n(n-1,3,dp)+count_n(n-1,5,dp)+count_n(n-1,9,dp))%mod;
        if(digit==9)
            dp[n][digit]=(count_n(n-1,2,dp)+count_n(n-1,4,dp)+count_n(n-1,8,dp))%mod;
    }
}
int main()
{
    int n;
    cin>>n;
    lli sum=0;
    int dp[n+1][10]={-1};
    rep(i,0,9)
    {
        sum=(sum+count_n(n,i,dp))%mod;
    }
    lli ans=(exponentMod(10,n,mod)-sum)%mod;
    cout<<ans<<"\n";
}
