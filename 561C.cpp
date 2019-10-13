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
	int i,j,mid;
	int count=0;
	//it will be nlogn
	for(r=n-1;r>=0;r--)
	{
		i=0;j=r;
		while(i<j)
		{
            mid=(i+j)/2;
			if(a[r]==2*a[mid])
				break;
			else if(a[r]>2*a[mid])
				i=mid+1;
			else
				j=mid-1;
		}
		count+=(j-mid);
	}
	cout<<count<<"\n";
}
