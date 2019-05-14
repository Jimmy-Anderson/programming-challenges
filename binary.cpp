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
  test()
  {
    int n,z,num;
    cin>>n>>z;
    vector<int>a;
    rep(i,0,n-1)
    {
      cin>>num;
      a.push_back(num);
    }
    if(n==1)
      cout<<a[0]<<"\n";
    else if(n==2)
    {
      if(a[0]==0&&a[1]==1)
        cout<<"1 0\n";
      else
        cout<<a[0]<<" "<<a[1]<<"\n";
    }
    else
    {
      while(z--)
      {
        int swap_no=0;
        rep(i,0,n-2)
        {
          if(a[i]==0&&a[i+1]==1)
          {
            swap_no++;
            a[i]=(a[i]+a[i+1])-(a[i+1]=a[i]);
            i++;
          }
        }
        if(swap_no==0)
          break;
      }
      rep(i,0,n-1)
        cout<<a[i]<<" ";
      cout<<"\n";
    }
  }
}
