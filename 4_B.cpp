#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
struct schedule{
  int day;
  int min_time;
  int max_time;
};
bool compare(schedule a,schedule b)
{
  bool x=a.max_time<b.max_time;
  return x;
}
int main()
{
  int n,sum;
  cin>>n>>sum;
  schedule test[n];
  rep(i,0,n-1)
  {
    test[i].day=i;
    cin>>test[i].min_time;
    cin>>test[i].max_time;
  }
  int max_sum=0;
  rep(i,0,n-1)
    max_sum+=test[i].max_time;
  if(max_sum<sum)
  {
    cout<<"NO\n";
    return 0;
  }
  sort(test,test+n,compare);
  int solution[n];
  int i;
  for(i=0;i<n;i++)
  {
    if(test[i].min_time<=sum)
    {
      solution[test[i].day]=test[i].min_time;
      sum-=test[i].min_time;
    }
    else
    {
        cout<<"NO\n";
        return 0;
    }
  }
  if(sum!=0)
  for(i=n-1;i>=0;i--)
  {
    if(sum>=0)
    {
      solution[test[i].day]=test[i].max_time;
      sum=sum+test[i].min_time-test[i].max_time;
    }
    else
        break;
  }

  cout<<"YES\n";
  rep(i,0,n-1)
  {
    cout<<solution[i]<<" ";
  }
}
