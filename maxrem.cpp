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
    lli n,num;
    cin>>n;
    vector<lli>a;
    rep(0,n,1)
    {
      cin>>num;
      a.push_back(num);
    }
    sort(a.begin(),a.end());
    lli i;
    for(i=n-1;i>0;i--)
      if(a[i]!=a[i-1])
        break;
    cout<<a[i-1]<<"\n";
  }
}
