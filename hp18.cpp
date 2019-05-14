#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b;
		cin>>n>>a>>b;
		int x[n];
		for(int i=0;i<n;i++)
			cin>>x[i];
		if(a==b)
		{
			int ca=0,cb=0,cab=0;
			for(int i=0;i<n;i++)
			{
				if(x[i]%a==0)
					cb++;
				if(x[i]%b==0)
					ca++;			
				if(x[i]%b==0&&x[i]%a==0)
					cab++;
			}
			if(cb==0)
				cout<<"ALICE"<<"\n";
			if((ca-cab)>0)
				cout<<"ALICE"<<"\n";
			else
				cout<<"BOB"<<"\n";
		}
		else
		{
			sort(x,x+n);
			stack <int> ca,cb;
			for(int i=0;i<n;i++)
			{
				if(x[i]%a==0)
					cb.push(x[i]);
				if(x[i]%b==0)
					ca.push(x[i]);
			}
			int f=0;
			while(!cb.empty()&&!ca.empty())
			{
				if(f==0)
				{
					if(!cb.empty())
					{	
						if(cb.top()==ca.top())
							ca.pop();
						cb.pop();
						f=1;
					}
				}
				else
				{
					if(!ca.empty())
					{
						if(cb.top()==ca.top())
							cb.pop();
						ca.pop();
						f=0;
					}
				}
			}
			if(cb.empty()&&!ca.empty())
				cout<<"ALICE"<<"\n";
			if(ca.empty()&&!cb.empty())
				cout<<"BOB"<<"\n";
			if(ca.empty()&&cb.empty())
			{
				if(f==0)
					cout<<"ALICE"<<"\n";
				else
					cout<<"BOB"<<"\n";
			}
		}
	}
}