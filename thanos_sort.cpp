#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int a[16];
int thanos_snap(int l,int r)
{
	if(l==r)
		return 1;
	int flag=0;
	for(int i=l+1;i<=r;i++)
	{
		if(a[i-1]>a[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		int mid=l+(r-l+1)/2;
        return max(thanos_snap(l,mid-1),thanos_snap(mid,r));
	}
	else
	{
		return r-l+1;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int result=thanos_snap(0,n-1);
	cout<<result<<"\n";
}
