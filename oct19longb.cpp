#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,q;
		cin>>n>>m>>q;
		vector<int>r(n,0);
		vector<int>c(m,0);
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			r[--x]++;
			c[--y]++;
		}
		lli re,ro,ce,co;
		re=ro=ce=co=0;
		for(int i=0;i<n;i++)
			if(r[i]%2==0)
				re++;
			else
				ro++;
		for(int i=0;i<m;i++)
			if(c[i]%2==0)
				ce++;
			else
				co++;
		cout<<re*co+ce*ro<<"\n";
	}
}