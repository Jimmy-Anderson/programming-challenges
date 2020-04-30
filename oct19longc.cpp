#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lli n,k,num;
		cin>>n>>k;
		num=3*n;
		int a[n];
		for(lli i=0;i<n;i++)
			cin>>a[i];
		
		if(n%2!=0&&k>=n)
			a[n/2]=0;
		k=k%num;
		for(lli j=0;j<k;j++)
		{
			lli i=j%n;
			a[i]=a[i]^a[n-i-1];
		}
		for(lli i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
	}
}