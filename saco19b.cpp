#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
	test()
	{
		lli n,k;
		cin>>n>>k;
		lli h[n];
		rep(0,n,1)
			cin>>h[i];
		lli cur_seq=0;
		lli last_bit=0;
		lli min=k;
		lli result=0;
		rep(0,n,1)
		{
			if(h[i]>=min)
			{
				cur_seq++;
				last_bit=i;
			}
			else
			{
				result+=((cur_seq)*(cur_seq-1)/2);
				cur_seq=0;
			}
		}
		if(last_bit==n-1)
            result+=((cur_seq)*(cur_seq-1)/2);
		cout<<result<<"\n";
	}
}
