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
		set<int>myset;
		rep(i,0,n)
		{
			cin>>A[i];
			myset.insert(A[i]);
		}
		A.clear();
		A.insert(A.begin(),myset.begin(),myset.end());	
		//cout<<A.size()<<"\n";
		int maxel=A[0];
		n=A.size();
		rep(i,0,n)
		{
			if(maxel<A[i])
				maxel=A[i];
		}
		int secmax=-1;
		rep(i,0,n)
		{
			if(A[i]!=maxel&&secmax<A[i])
				secmax=A[i];
		}
		//cout<<maxel<<" "<<secmax<<"\n";
		int gc=0;
		rep(i,0,n)
		{
			if(A[i]==maxel||A[i]==secmax)
				continue;
			else
				gc=gcd(gc,A[i]);
		}
		int maxgc=max(gcd(gc,maxel)+secmax,gcd(gc,secmax)+maxel);
		if(n==1)
			maxgc=2*A[0];
		cout<<maxgc<<"\n";
	}
}