#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
bool do_me(lli n,lli m,bool x)
{
	if(n%m==0)
		return x;
	if(x==1)
	{
		if(n/m>1)
			return 1;
			return do_me(m,n%m,!x);
	}
	if(n/m>1)
	return 0;
	return do_me(m,n%m,!x);
}
int main()
{
	test()
	{
		lli n,m,x,y,steps=0;
		cin>>n>>m;
		x=n>m?n:m;
		y=n<m?n:m;
		if(do_me(x,y,1))
			cout<<"Ari\n";
		else
			cout<<"Rich\n";
	}
}
