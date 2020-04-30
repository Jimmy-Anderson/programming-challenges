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
	lli n;
	cin>>n;
	n--;
	//Find factoriad of 13
	lli factoriad[13]={0};
	int i=1;
	lli a=n;
	while(a!=0)
	{
		factoriad[13-i]=a%i;
		a/=i;
		i++;
	}

	//Get permutation from the factoriad
	string s="abcdefghijklm";
	string res="";
	for(int i=0;i<13;i++)
	{
		int pos=factoriad[i];//position of the permutation
		//cout<<s<<"\n";
		res.push_back(s[pos]);
		s=s.erase(pos,1);
	}
	cout<<res<<"\n";

}