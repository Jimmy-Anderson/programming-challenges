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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<lli>a(n,0);
		vector<lli>b(n,0);
		vector<lli>amodb(n,0);
		vector<lli>prefix(n,0);
		vector<lli>suffix(n,0);
		lli bmin=INT_MAX;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			bmin=min(bmin,b[i]);
			amodb[i]=a[i]%b[i];
		}
		sort(amodb.begin(),amodb.end());
		prefix[0]=amodb[0];
		suffix[n-1]=amodb[n-1];
		for(int i=1;i<n;i++)
			prefix[i]=prefix[i-1]+amodb[i];
		for(int i=n-1;i>=0;i--)
			suffix[i]=suffix[i+1]+amodb[i];
		lli stepsmin=INT_MAX;
		for(int y=0;y<bmin;y++)
		{
			lli steps=0;
			
			stepsmin=min(steps,stepsmin);
		}
		cout<<stepsmin<<"\n";
	}
}