#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
	lli n,m;
	cin>>n>>m;
	lli a[n],b[m];
	for(lli i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(lli i=0;i<m;i++)
	{
		cin>>b[i];
	}
	vector <lli> sum;
	lli c=0;
	for(lli i=0;i<n;i++)
	{
		for(lli j=0;j<m;j++)
		{
			lli s=a[i]+b[j];
			if(!binary_search(sum.begin(),sum.end(),s))
			{
				sum.push_back(s);
				sort(sum.begin(),sum.end());
				c++;
				if(c<m+n)
					cout<<i<<" "<<j<<"\n";
			}
			if(c==m+n)
				break;
		}
		if(c==m+n)
			break;
	}
}
