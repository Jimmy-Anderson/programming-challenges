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
	{
		cin>>a[i];
		a[i]=abs(a[i]);
	}
	sort(a,a+n);

    lli ans=0,l=0,i;
	for (i=0;i<n;i++)
  {
		while(2*a[l]<a[i])
            l++;
		ans+=i-l;
	}

    cout<<ans;
    return 0;
}
