#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

struct team{
	char team_leader[21];
	char team1[21];
	char team2[21];
};

int main()
{
	test()
	{
		int n,q;
		cin>>n>>q;
		team a[n+1];
		int y=3*n;
		for(int i=1;i<=y;i++)
		{
			int tnum;
			char name[21];
			char teamlead;
			cin>>tnum>>name>>teamlead;
			int qn=strlen(name);
			int p=strlen(a[tnum].team1);
			if(teamlead=='Y')
				strncpy(a[tnum].team_leader,name,qn+1);
			else
			{
				if(p)
				{
					if( strcmp(a[tnum].team1,name)<0)
				   	{
				   		strncpy(a[tnum].team2, name,qn+1);
				    }
				    else
				    {
				        strncpy(a[tnum].team2, a[tnum].team1, p+1);
				   		strncpy(a[tnum].team1, name, qn+1);
				    }
				}
				else
				{
					strncpy(a[tnum].team1, name, qn+1);
				}
			}
		}
		while(q--)
		{
			int w,z;
			cin>>w>>z;
			if(z==1)
				cout<<a[w].team_leader<<"\n";
			if(z==2)
				cout<<a[w].team1<<"\n";
			if(z==3)
				cout<<a[w].team2<<"\n";
		}
	}
}
