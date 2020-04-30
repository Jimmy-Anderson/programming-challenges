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
	int n,num;
	cin>>n;
	vector<int> a;
	vector<int>sequence;
	vector<char>moves;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		a.push_back(num);
	}
	string res;
	int last=0;
	int l=0,r=n-1;
	while(l<=r)
	{
		vector< pair<int,char> >cur;
		if(last<a[l])
			cur.push_back({a[l],'L'});
		if(last<a[r])
			cur.push_back({a[r],'R'});
		sort(cur.begin(),cur.end());
		if(int(cur.size())==2&&cur[0].first!=cur[1].first)
		{
			cur.pop_back();
		}
		if(int(cur.size())==1)
		{
			if(cur[0].second=='L')
			{
				res+="L";
				last=a[l];
				++l;
			}
			else
			{
				res+="R";
				last=a[r];
				--r;
			}
		}
		else if(int(cur.size())==2)
		{
			int cl=1,cr=1;
			while(cl+l<=r && a[l+cl]>a[cl+l-1])
				++cl;
			while(r-cr>=l && a[r-cr]>a[r-cr+1])
				++cr;
			if(cl>cr)
			{
				res+=string(cl,'L');
			}
			else
				res+=string(cr,'R');
			break;
		}
		else
			break;

	}
	 cout<<res.size()<<"\n"<<res<<"\n";
}
