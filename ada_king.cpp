#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

int a[9][9];
int coun=0,r,c,k;
int main()
{
	test()
	{
		cin>>r>>c>>k;
		int dx,dy;
		dx=min(c+k,8)-max(c-k,1)+1;
		dy=min(r+k,8)-max(r-k,1)+1;
		int ar=dx*dy;
		cout<<ar<<"\n";
	}
}
