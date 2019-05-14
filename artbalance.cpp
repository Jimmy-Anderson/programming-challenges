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
		string s;
		cin>>s;
		int len=s.length();
		int fre[26]={0};
		for(int i=0;i<len;i++)
		{
			fre[s[i]-'A']++;
		}
		sort(fre,fre+26,greater<int>());
		int ans[26];
		for(int i=0;i<26;i++)
			ans[i]=INT_MAX;
		for(int i=1;i<=26;i++)
		{
			int sum=0;
			if(len%i==0)
			{
				int q=len/i;
				for(int j=0;j<i;j++)
				{
					if(q>=fre[j])
						sum+=(q-fre[j]);
				}
				ans[i-1]=sum;
			}
		}
		sort(ans,ans+26);
		cout<<ans[0]<<"\n";
	}	
}