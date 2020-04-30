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
  map<int,vector<int>>mp;
  int i=1;
  int arr[129]={0};
  int freq[129]={0};
  map<int,int>ans;
  ans[0]=1;
  freq[0]=1;
  for(int i=1;i<129;i++)
  {
    int x=arr[i-1];
    int ind=-1;
    for(int j=i-2;j>=0;j--)
    {
      if(arr[j]==x)
      {
        ind=j;
        break;
      }
    }
    if(ind==-1)
      arr[i]=0;
    else
      arr[i]=i-1-ind;
    freq[arr[i]]++;
    ans[i]=freq[arr[i]];
  }
  // rep(i,0,127)
  //   cout<<arr[i]<<" ";
  // cout<<"\n";
  test()
  {
    int n;
    cin>>n;
    cout<<ans[n-1]<<"\n";
  }
}
