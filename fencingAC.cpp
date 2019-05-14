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
		map<int,vector<int> >a,b;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			b[y].push_back(x);
		}
		map<int,vector<int> >::iterator itr1,itr2;
		for(itr1=a.begin();itr1!=a.end();itr1++)
		{
			sort((itr1->second).begin(),(itr1->second).end());
			for(int i=1;i<(itr1->second).size();i++)
				if(abs((itr1->second)[i]-(itr1->second)[i-1])==1)
					count-=2;
		}
		for(itr1=b.begin();itr1!=b.end();itr1++)
		{
			sort((itr1->second).begin(),(itr1->second).end());
			for(int i=1;i<(itr1->second).size();i++)
				if(abs((itr1->second)[i]-(itr1->second)[i-1])==1)
					count-=2;
		}
		cout<<count<<"\n";
	}
}