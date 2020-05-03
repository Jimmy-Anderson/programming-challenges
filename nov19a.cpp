#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<string>s(n);
    rep(i,0,n-1)
      cin>>s[i];
    int count=0;
    rep(k,0,9)
    {
      int r=0;
      rep(i,0,n-1)
        r^=(s[i][k]-'0');
      if(r==1)
        count++;
    }
    cout<<count<<"\n";


  }
}
