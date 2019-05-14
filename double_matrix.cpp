#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int n,m;
int check_matrix(lli a[][50],int i,int j)
{
  for(int k=0;k<n-1;k++)
  {
    if(a[k][j]>=a[k+1][j])
      return 0;
  }
  for(int k=0;k<m-1;k++)
  {
    if(a[i][k]>=a[i][k+1])
      return 0;
  }
  return 1;
};

int main()
{
  cin>>n>>m;
  lli a[n][50],b[n][50];
  rep(i,0,n-1)
    rep(j,0,m-1)
      cin>>a[i][j];
  rep(i,0,n-1)
    rep(j,0,m-1)
      cin>>b[i][j];
  int flag=1;
  rep(i,0,n-1)
    rep(j,0,m-1)
    {
      if(check_matrix(a,i,j)&&check_matrix(b,i,j))
        continue;
      else
      {
        b[i][j]=a[i][j]+b[i][j]-(a[i][j]=b[i][j]);//swap
        if(check_matrix(a,i,j)&&check_matrix(b,i,j))
          continue;
        else
        {
          b[i][j]=a[i][j]+b[i][j]-(a[i][j]=b[i][j]);
        }
      }
    }
  rep(i,0,n-1)
    rep(j,0,m-1)
        if(!check_matrix(a,i,j)||!check_matrix(b,i,j))
            flag=0;
  if(flag==1)
    cout<<"Possible\n";
  else
    cout<<"Impossible\n";
}
