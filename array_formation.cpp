#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
void prime_check(int n,vector<bool>&prime_set)
{
	rep(0,n,1)
		prime_set.push_back(true);
	for(int i=2;i*i<=n;i++)
	{
		if(prime_set[i]==true)
		{
			for(int j=i*i ; j<=n; j+=i)
				prime_set[j]=false;
		}
	} 
}
int main()
{
	vector <bool> prime_set;
	prime_check(1000001,prime_set);
	int n;
	cin>>n;
	int a[n];
	rep(0,n,1)
		cin>>a[i];

	stack<int>composite;
	queue<int>prime;
	for (int i = 0; i < n; ++i)
	{
		if(prime_set[a[i]])
			prime.push(a[i]);
		if(!prime_set[a[i]])
			composite.push(a[i]);
	}
	while(!prime.empty())
	{
		cout<<prime.front()<<" ";
		prime.pop();
	}
	cout<<"\n";
	while(!composite.empty())
	{
		cout<<composite.top()<<" ";
		composite.pop();
	}
}