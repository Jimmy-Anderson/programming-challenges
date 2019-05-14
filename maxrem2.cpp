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
		lli n,num,max=0,smax=0;
		cin>>n;
		vector<lli>a;
		for(lli i=0;i<n;i++)
		{
			cin>>num;
			a.push_back(num);
			if(a[i]>max)
				max=a[i];
		}		
		for(lli i=0;i<n;i++)
			if(a[i]>smax&&a[i]<max)
				smax=a[i];
		cout<<smax<<"\n";
}