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
		int a[n];
		int count1=0,count2=0,count3=0;
		rep(i,0,n)
		{
			cin>>a[i];
			int rem=a[i]%3;
			if(rem==1)
				count1++;
			if(rem==2)
				count2++;
			if(rem==0)
				count3++;
		}
		int ans=0;
		if(count1==count2)
			ans=count3+count2;
		else if(count1>count2)
			ans=count3+count2+(count1-count2)/3;
		else
			ans=count3+count1+(count2-count1)/3;
		cout<<ans<<"\n";

	}
}