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
  lli i,j,k;
  cin>>i>>j>>k;
  long long int len;
  if(i==j)
    len=i+j+2*k;
    else
    {
      int mina,maxa;
      mina=min(i,j);
      maxa=max(i,j);
      len=2*k+2*mina+1;
    }
    cout<<len<<"\n";
}
