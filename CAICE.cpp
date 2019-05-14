#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;    cin>>t;    while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    test()
    {
        lli n;
        cin>>n;
        lli ans=((n%mod)*(n+1)%mod/2)%mod;
        cout<<ans<<"\n";
    }
}