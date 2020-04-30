#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
	int n;
	cin>>n;
	lli a[n];
	rep(i,0,n)
		cin>>a[i];
	int x=0;
	rep(i,0,n-1)
		rep(j,i+1,n)
		{
			lli mina,maxa,minv,maxv;
			mina=min(abs(a[i]),abs(a[j]));
			maxa=max(abs(a[i]),abs(a[j]));
			minv=min(abs(a[i]+a[j]),abs(a[j]-a[i]));
			maxv=max(abs(a[i]+a[j]),abs(a[j]-a[i]));
			if(mina>=minv&&maxa<=maxv)
				x++;
		}
	cout<<x<<"\n";
}