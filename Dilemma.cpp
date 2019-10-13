#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
void solve(string &s,int l,int r,int flip)
{
	if(l>r)
		return;
	for(int i=l;i<=r;i++)
	{
		if((s[i]=='1'&&flip==0)||(s[i]=='0'&&flip==1))
		{
			s[i]='9';
			flip=!flip;
			solve(s,l,i-1,flip);
			solve(s,i+1,r,flip);
			break;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int len=s.length();
		solve(s,0,len-1,0);
		// cout<<s<<"\n";
		int i;
		for(i=0;i<len;i++)
		{
			if(s[i]!='9')
				break;
		}
		if(i==len)
				cout<<"WIN\n";
		else
			cout<<"LOSE\n";
	}
}