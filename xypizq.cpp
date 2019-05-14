#include<bits/stdc++.h>
#define lli long long int
using namespace std;

lli gcd(lli a,lli b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

lli reduce(lli ans[])
{
	lli gd=gcd(ans[0],ans[1]);
	ans[0]/=gd;
	ans[1]/=gd;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		lli n,t,x,y,z;
		cin>>n>>t>>x>>y>>z;
		lli angle=(2*n+1);
		lli ans[2];
		if(t==1)
		{
			if(y==0)
			{
				ans[0]=1;
				ans[1]=angle;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";
			}
			else if(y==n&&z==n)
			{
				ans[0]=2*n-1;
				ans[1]=4*n+2;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
			else if((x<y&&z<y)||(x>y&&z>y))
			{
				ans[0]=z;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
			else if((x<y&&z>y)||(x>y&&z<y))
			{
				ans[0]=2*n+1-z;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
		}
		else if(t==3)
		{
			if(y==n)
			{
				ans[0]=1;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
			else
			{
				ans[0]=2*n+1-2*y;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
		}
		else if(t==3)
		{
			if(y==n&&z==n)
			{
				ans[0]=2*n-1;
				ans[1]=4*n+2;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
			else if((x<y&&z<y)||(x>y&&z>y))
			{
				ans[0]=x;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
			else if((x<y&&z>y)||(x>y&&z<y))
			{
				ans[0]=2*n+1-z;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
		}
		else if(t==4)
		{
			if(y==n)
			{
				ans[0]=1;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
			else
			{
				ans[0]=2*n+1-2*y;
				ans[1]=2*n+1;
				reduce(ans);
				cout<<ans[0]<<" "<<ans[1]<<"\n";	
			}
		}
	}

}