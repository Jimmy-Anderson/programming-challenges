#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
	int h1,h2,m1,m2,dh,dm,diff,ansh1,ansh,ansm;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int i=0;
	while(s1[i])
	{
		if(s1[i]!=':')
			
	}
	dh=h2-h1;
	dm=m2-m1;
	diff=(dh*60+dm)/2;
	ansh1=h1*60+m1;
	ansh1=ansh1+diff;
	ansh=ansh1/60;
	ansm=ansh1%60;
	cout<<ansh<<" "<<ansm<<"\n";
}