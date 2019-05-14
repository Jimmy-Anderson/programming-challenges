#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define test() int t;	cin>>t;	while(t--)
using namespace std;
int main()
{
	test()
	{
		string s,a,n;
		cin>>s;
		vector<int>posa,posb;
		rep(i,0,s.length())
		{
			if(isalpha(s[i])!=0)
			{
				a.push_back(s[i]);
				s[i]='a';
			}
			if(isdigit(s[i])!=0)
			{
				n.push_back(s[i]);
				s[i]='d';
			}
		}
		sort(a.begin(),a.end());
		sort(n.begin(),n.end());
		int j=0,k=0;
		rep(i,0,s.length())
		{
			if(s[i]=='a')
				cout<<a[j++];
			if(s[i]=='d')
				cout<<n[k++];
		}
		cout<<"\n";
	}
}