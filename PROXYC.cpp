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
		int l;
		cin>>l;
		string s;
		cin>>s;
		int cp=0,ca=0,cq=0;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='P')
				cp++;
			else if(s[i]=='A')
				ca++;
		}
		int count=0;
		for(int i=2;i<l-2;i++)
		{
			if(((float)cp/(float)l)>=0.75)
				break;
			if(s[i]=='A'&&(s[i-1]=='P'||s[i-2]=='P')&&(s[i+1]=='P'||s[i+2]=='P'))
			{
				count++;
				cp++;
				ca--;
			}
		}
		if(((float)cp/(float)l)<0.75)
			count=-1;
		cout<<count<<"\n";
	}
}