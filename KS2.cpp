#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int check(int a,int b)
{
	set<int>s;
	if(a==0||b==0)
		s.insert(0);
	while(a>0)
	{
		s.insert(a%10);
		a/=10;
	}
	while(b>0)
	{
		s.insert(b%10);
		b/=10;
	}
	if(s.size()==2)
		return 1;
	else 
		return 0;
}
int main()
{
	//vector<int>v;
	int count=0;
	int num=99999;
	for(int i=0;i<=num;i++)
	{
		if(check(i,num-i))
			cout<<++count<<" "<<i<<" "<<num-i<<"\n";
	}
	// //test()
	// {
	// 	//int n;
	// 	//cin>>n;
	// 	//cout<<v[n]<<"\n";
	// }
}