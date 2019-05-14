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
	test()
	{
		int n;
		cin>>n;
		string s;
		char c;
		cin>>s>>c;
		lli sum=0;
		vector<int>v;
		for(int i=0;i<n;i++)
		{
			if(s[i]==c)
				v.push_back(i);
		}
		for(int i=0;i<v.size();i++)
		{
			if(i==0)
				sum=sum+(v[i]+1)*(n-v[i]);
			else
				sum=sum+(v[i]-v[i-1])*(n-v[i]);
		}
		cout<<sum<<"\n";
	}	
}