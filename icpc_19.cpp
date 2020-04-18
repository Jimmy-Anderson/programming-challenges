#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
typedef struct itv{
	int l;
	int r;
	int v;
}itv;
bool compare(itv i1,itv i2)
{
	return i1.l<i2.l;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;
		vector<itv>list(n);
		for(lli i=0;i<n;i++)
		{
			cin>>list[i].l>>list[i].r>>list[i].v;
		}
		sort(list.begin(),list.end(),compare);
		stack<itv>s;
		int count=1,flag=0;
		s.push(list[0]);
		for(int i=1;i<n;i++)
		{
			itv top=s.top();
			if(top.r<list[i].r)
			{
				s.push(list[i]);
				count=1;
			}
			else
			{
				s.push(list[i]);
				count++;
				if(count>=3)
				{
					if((list[i].v==list[i-1].v)&&(list[i-1].v==list[i-2].v))
					{
						flag=1;
					}
				}
			}
		}
		if(flag==1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}