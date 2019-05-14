#include<bits/stdc++.h>

#define lli long long int; 
using namespace std;

typedef struct node{
	int index;
	int data;
}node;

int main()
{
	int n,m;
	cin>>n>>m;
	node a[n];
	node b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].data;
		a[i].index=i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i].data;
		b[i].index=i;
	}

	for(int i=0;i<n;i++)
	{
		int c=0;
		for(int j=0;j<n-1;j++)
		{
			if(a[j].data>a[j+1].data)
			{
				a[j].data=a[j].data+a[j+1].data;
				a[j+1].data=a[j].data-a[j+1].data;
				a[j].data=a[j].data-a[j+1].data;
				a[j].index=a[j].index+a[j+1].index;
				a[j+1].index=a[j].index-a[j+1].index;
				a[j].index=a[j].index-a[j+1].index;
				c++;
			}
		}
		if(c==0)
			break;
	}
	for(int i=0;i<m;i++)
	{
		int c=0;
		for(int j=0;j<m-1;j++)
		{
			if(b[j].data>b[j+1].data)
			{
				b[j].data=b[j].data+b[j+1].data;
				b[j+1].data=b[j].data-b[j+1].data;
				b[j].data=b[j].data-b[j+1].data;
				b[j].index=b[j].index+b[j+1].index;
				b[j+1].index=b[j].index-b[j+1].index;
				b[j].index=b[j].index-b[j+1].index;
				c++;
			}
		}
		if(c==0)
			break;
	}
	for(int i=n-1;i>0;i--)
	{
		cout<<a[i].index<<" "<<b[m-1].index<<"\n";
	}
	for(int i=0;i<m;i++)
	{
		cout<<a[0].index<<" "<<b[i].index<<"\n";
	}

}