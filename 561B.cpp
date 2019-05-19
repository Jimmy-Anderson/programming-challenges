#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
//sieve of erastothenes
void prime_check(int n,vector<bool>&prime_set)
{
	rep(i,0,n)
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
void vowelly_word(int k)
{
	vector<bool>isPrime;
	prime_check(1001,isPrime);
	if(k<25||isPrime[k])
		cout<<"-1\n";
	else
	{
		int n,m;
		n=(int)sqrt(k);
		while(k%n!=0)
		{
			if(isPrime[n]&&k%n==0)
				break;
			n--;
		}
		m=k/n;
		string s="aeiou";
		if(n<5||m<5)
			cout<<"-1\n";
		else
			for(int i=0;i<n;i++)
			{
				int k;
				for(int j=0;j<m;j++)
				{
					k=(i+j)%5;
					cout<<s[k];
				}
			}
		cout<<"\n";
	}
}
int main()
{
	int k;
	cin>>k;
	vowelly_word(k);
}