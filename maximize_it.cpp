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
	int n;
	cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int a1[n],a2[n];
	for(int i=0;i<n;i++)
	{
		a1[i]=(int)(s1[i]-'A');
		a2[i]=(int)(s2[i]-'A');
	}
	int count=0;
	for(int i=0;i<n;i++)
	{
		if((a1[i]+13)%26<=a2[i])
		{
			count++;
			count+=a2[i]-(a1[i]+13)%26;
		}
		else if((a1[i]+13)%26>a2[i])
		{
			count+=a2[i]-a1[i];	
		}
	}
	cout<<count<<"\n";
}