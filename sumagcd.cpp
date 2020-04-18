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
		sort(A.begin(),A.end());
		int last=A[n-1];
		int gc=A[n-1];
		int j=n-1;
		while(true)
		{
			int x=gcd(gc,A[j]);
			if(x>=gc)
				gc=x;
			else
				break;
			j--;
		}
		last=A[j];
		int gc2=A[0];
		for(int i=1;i<j;i++)
		{
			if(A[i]==last)
				break;
			else
			{
				gc2=gcd(gc2,A[i]);
			}
		}
		cout<<(gc+gc2)<<"\n";
	}
}