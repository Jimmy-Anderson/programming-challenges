#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};
int main()
{
	test()
	{
		int n,m,k;
		cin>>n>>m>>k;
		int count=4*k;
		multimap<int,int>a,b;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			a.insert(make_pair(x,y));
			b.insert(make_pair(y,x));
		}
		multimap<int,int>::iterator itr1,itr2;
		itr1=a.begin();
		itr2=++itr1;
		for(itr1=a.begin();itr2!=a.end();itr1++,itr2++)
		{
			if(itr1->first==itr2->first)
			{
				if(abs(itr1->second-itr2->second)==1)
					count-=2;
			}
		}
		itr1=b.begin();
		itr2=++itr1;
		for(itr1=b.begin();itr2!=b.end();itr1++,itr2++)
		{
			if(itr1->first==itr2->first)
			{
				if(abs(itr1->second-itr2->second)==1)
					count-=2;
			}
		}
		cout<<count<<"\n";
	}
}