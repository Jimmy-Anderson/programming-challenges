#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int>degree(n,0);
		vector<int>uarr(m,0);
		vector<int>varr(m,0);
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			uarr[i]=u-1;
			varr[i]=v-1;
			degree[u-1]++;
			degree[v-1]++;
		}
		if(m%2==0)
		{
			cout<<"1\n";
			for(int i=0;i<n;i++)
				cout<<"1 ";
			cout<<"\n";
		}
		else
		{
			int odddegree=0,oddver;
			for(int i=0;i<n;i++)
				if(degree[i]&1)
				{
					odddegree=1;
					oddver=i;
					break;
				}
			if(!odddegree)
			{
				cout<<"3\n";
				vector<int>ans(n,3);
				int i=0;
				for(;i<n;i++)
					if(degree[i]>0&&degree[i]%2==0)
						break;
				degree[i]=0;
				ans[i]=1;
				for(int j=0;j<m;j++)
				{
					if(uarr[j]==i)
						degree[varr[j]]--;
					else if(varr[j]==i)
						degree[uarr[j]]--;
				}
				for(int j=0;j<n;j++)
					if(degree[j]&1)
					{
						ans[j]=2;
						break;
					}
				for(int j=0;j<n;j++)
						cout<<ans[j]<<" ";
					cout<<"\n";
			}
			else
			{
				cout<<"2\n";
				for(int i=0;i<n;i++)
					if(i==oddver)
						cout<<"2 ";
					else
						cout<<"1 ";
				cout<<"\n";
			}
		}
	}
}