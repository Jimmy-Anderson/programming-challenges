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
  vector<lli>res;
  res.push_back(0);
  res.push_back(1);
  res.push_back(5);
  lli ans=5;
  for(int i=3;i<=1000000;i++)
  {
      ans=((ans+i)%mod+(ans%mod*i%mod)%mod)%mod;
      res.push_back(ans);
  }

  test()
  {
    int n;
    cin>>n;
    cout<<res[n]<<"\n";
  }
}
