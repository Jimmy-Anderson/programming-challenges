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
	int n,i;
	cin>>n;
	i=n;
	int freq[26]={0};
	while(i--)	
	{
		string s;
		cin>>s;
		int ch=(int)(s[0]-'a');
		freq[ch]++;
	}
	int x=0,y;
	for(i=0;i<26;i++)
	{
		if(freq[i]==0||freq[i]==1||freq[i]==2)
			continue;
		else if(freq[i]%2==0)
		{
			y=freq[i]/2;
			x+=(y*(y-1));
		}
		else if(freq[i]%2!=0)
		{
			y=freq[i]/2;
			if(y==1)
				x++;
			else
				x+=(y*y);
		}
	}
	cout<<x<<"\n";
}