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
		int n,d;
		cin>>n;
		cin>>d;
		vector <int> num;
		while(n>0)
		{
			int dg=n%10;
			num.push_back(dg);
			n=n/10;
		}
		reverse(num.begin(),num.end());
		int x=num.size();
		for(int i=1;i<x;i++)
		{
			if(num[i-1]>=num[i])
			{
				num.erase(i-1);
				num.push_back(d);
			}
			if(num[i]>d)
			{
				num.erase(i);
				num.push_back(d);
			}
			if(num[0]>d)
			{
				num.erase(0)
				num.push_back(d);
			}
		}
		
		for(int i=0;i<num.size();i++)
		{
				cout<<num[i];
		}
			cout<<"\n";
	}
}
