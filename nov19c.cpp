#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
typedef struct point
{
  int x;
  int y;
}point;
long double distance(point a,point b)
{
  long double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
  return d;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,m,o,x,y;
    cin>>x>>y;
    cin>>n>>m>>o;
    vector<point>a(n);
    vector<point>b(m);
    vector<point>c(o);
    for(int i=0;i<n;i++)
      cin>>a[i].x>>a[i].y;
    for(int i=0;i<m;i++)
      cin>>b[i].x>>b[i].y;
    for(int i=0;i<o;i++)
      cin>>c[i].x>>c[i].y;
    point w;
    w.x=x;
    w.y=y;
    long double d1,d2,d3,mind=DBL_MAX;
    for(int i=0;i<n;i++)
    {
      point s1=a[i];
      d1=distance(w,s1);
      for(int j=0;j<m;j++)
      {
        point s2=b[j];
        d2=distance(s1,s2);
        for(int k=0;k<o;k++)
        {
          point s3=c[k];
          d3=distance(s2,s3);
          mind=min(mind,d1+d2+d3);
        }
      }
    }
    for(int j=0;j<m;j++)
    {
      point s1=b[j];
      d1=distance(w,s1);
      for(int i=0;i<n;i++)
      {
        point s2=a[i];
        d2=distance(s1,s2);
        for(int k=0;k<o;k++)
        {
          point s3=c[k];
          d3=distance(s2,s3);
          mind=min(mind,d1+d2+d3);
        }
      }
    }
    cout<<setprecision(8)<<mind<<endl;
  }
}
