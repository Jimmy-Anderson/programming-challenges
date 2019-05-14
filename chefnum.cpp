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
		int p=0;
		int nt=0;
		int num;
		for(int i=0;i<n;i++)
		{
			cin>>num;
			if(num>0)
				p++;
			if(num<0)
				nt++;
		}
		if(p==0||nt==0)
		{
			if(p!=0)
				cout<<p<<" "<<p<<"\n";
			if(nt!=0)
				cout<<nt<<" "<<nt<<"\n";
		}
		else
			cout<<max(p,nt)<<" "<<min(p,nt)<<"\n";

	}	
}