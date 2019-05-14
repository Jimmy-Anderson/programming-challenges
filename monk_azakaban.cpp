#include<bits/stdc++.h>
#define lli long long int
#define test() int t;	cin>>t;	while(t--)
#define mod 1000000007
using namespace std;
int main()
{
	lli n;
	cin>>n;
	lli arr[n];
	for(lli i=0;i<n;i++)
		cin>>arr[i];
	stack <lli> a;
	stack <lli> index1;
	lli left[n];
	lli right[n];
	for(lli i=0;i<n;i++)
	{
		while(!a.empty()&&a.top()<=arr[i])
		{
			a.pop();
			index1.pop();
		}
		if(a.empty())
			left[i]=-1;
		else
			left[i]=index1.top();
		a.push(arr[i]);
		index1.push(i+1);
	}
	stack <lli> b;
	stack <lli> index2;
	for(lli i=n-1;i>=0;i--)
	{
		while(!b.empty()&&b.top()<=arr[i])
		{
			b.pop();
			index2.pop();
		}
		if(b.empty())
			right[i]=-1;
		else
			right[i]=index2.top();
		b.push(arr[i]);
		index2.push(i+1);
	}
	for(lli i=0;i<n;i++)
	{
		cout<<(left[i]+right[i])<<" ";
	}
}