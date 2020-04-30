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
	test()
	{
		int n;
		cin>>n;
		vector<int>a(n,0);
		rep(i,0,n)
			cin>>a[i];
		unordered_map< int, set<int>> fact;
		unordered_map<int,set<int>> ::iterator itr1,itr2,itr3;

		for(int i=0;i<n;i++)
		{
			int num=a[i];
			for(int j=1;j<=sqrt(num);j++)
			{
				if(num%j==0)
					fact[j].insert(i);
				if(j!=(num/j))
					fact[num/j].insert(i);
			}
		}
		int max=0;
		for(itr1=fact.begin();itr1!=fact.end();itr1++)
		{
			itr3=itr1;
			itr2=++itr1;
			itr1=itr3;
			for(	;itr2!=fact.end();itr2++)
			{
				int b,c;
				b=itr1->first;
				c=itr2->first;
				set<int>sb(itr1->second);
				set<int>sc(itr2->second);
				sb.insert(sc.begin(),sc.end());
				if(sb.size()==n&&(b+c)>max)
					max=b+c;

			}
		}
		cout<<max<<"\n";
	}
}