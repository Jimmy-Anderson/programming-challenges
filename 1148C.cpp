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
  int n;
  cin>>n;
  int arr[n+1];
  arr[0]=0;
  rep(i,1,n)
    cin>>arr[i];
  vector<pair<int,int>>v;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]!=i)
    {
      v.push_back({arr[i],arr[arr[i]]});
      arr[i]=(arr[i]+arr[arr[i]])-(arr[arr[i]]=arr[i]);//swapping arr[i]andarr[arr[i]];

    }
  }
  cout<<v.size()<<"\n";
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i].first<<" "<<v[i].second<<"\n";
  }
}
