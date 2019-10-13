#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	test()
	{
		int n;
		cin>>n;
		vector<int>A(n,0);
		rep(i,0,n)
			cin>>A[i];
		int x=0,y=0,z=0;
		for(int i=0;i<n;i++)
		{
			int p,q,r;
			p=gcd(x,A[i])+y;
			q=gcd(y,A[i])+x;
			r=gcd(x,y)+A[i];
			int maxd=max(p,max(q,r));
			if(maxd==p)
			{
				x=gcd(x,A[i]);
			}
			else if(maxd==q)
			{
				y=gcd(y,A[i]);
			}
			else if(maxd==r)
			{
				x=gcd(x,y);
				y=A[i];
			}
		}
		cout<<x+y<<"\n";
	}
}