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
	int n,s;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		double a;
		if(n==1)
		{
			if(s==0)
				cout<<"1\n";
			else
				cout<<"-1\n";
		}
		else if(s==0)
		{
			for(int i=0;i<n;i++)
				cout<<"1 ";
			cout<<"\n";
		}
		else if(n&1)
		{
			a=sqrt(((double)n)/(n-1))*s;
			for(int i=0;i<n;i++)
			{
				if(i==0)
					cout<<"0 ";
				else if(i&1)
					cout<<(a*-1)<<" ";
				else
					cout<<a<<" ";
			}
			cout<<"\n";
		}
		else
		{
			if(s==0)
				a=1;
			else
				a=s;
			for(int i=0;i<n;i++)
			{
				if(i&1)
					cout<<(a*-1)<<" ";
				else
					cout<<a<<" ";
			}
			cout<<"\n";
		}
	}
}