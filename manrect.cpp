#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define max 1000000000
using namespace std;
int main()
{
	test()
	{
		lli xl,yl,xu,yu;
		lli a,b,c,d,e;
		cout<<"Q "<<0<<" "<<0<<"\n"<<flush;
		cin>>a;
		cout<<"Q "<<max<<" "<<0<<"\n"<<flush;
		cin>>b;
		cout<<"Q "<<max<<" "<<max<<"\n"<<flush;
		cin>>c;
		cout<<"Q "<<0<<" "<<max<<"\n"<<flush;
		cin>>d;
		lli xavg=(a-b+max)/2;
		lli yavg=(b-c+max)/2;
		cout<<"Q "<<xavg<<" "<<0<<"\n"<<flush;
		cin>>yl;
		cout<<"Q "<<0<<" "<<yavg<<"\n"<<flush;
		cin>>xl;
		xu=max+yl-b;
		yu=xl+max-d;
		cout<<"A "<<xl<<" "<<yl<<" "<<xu<<" "<<yu<<"\n"<<flush;
		cin>>e;
	}	
	return 0;

}