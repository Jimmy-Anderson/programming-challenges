#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(int i=a;i<b;i+=c)
#define repd(a,b,c) for(int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio; ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
	fastio
	lli n,k;
	cin>>n>>k;
	lli max=0;
	vector <lli> a;
	rep(0,n,1)
	{
		lli num;
		cin>>num;
		a.push_back(num);
	}
	rep(0,k,1)
	{
		if(k%2==0&&i%2==0&&a[i]>=max)
			max=a[i];
		else if(k%2!=0&&i%2!=0&&a[i]>=max)
			max=a[i];
		else
			max=-1;
	}
	cout<<max<<"\n";
}