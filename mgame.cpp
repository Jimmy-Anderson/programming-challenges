#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,p;
		cin>>n>>p;
		long long int sum;
		long long int r=n/2+1;
		long long int max=n%r;
		if(n==1||n==2)
			sum=p*p*p;
		else
			sum=(p-max)*(p-max)+(p-max)*(p-n)+(p-n)*(p-n);
		cout<<sum<<"\n";
	}

}