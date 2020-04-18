#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

static int total_nodes;
void printSubset(int s[],int size)
{
	cout<<"Hello\n";
	//cout<<setw(4);
	for(int i=0;i<size;i++)
		cout<<s[i];
	cout<<"\n";
}
int subsetSum(int s[],int t[],int s_size,int t_size,int itr,int t_sum)
{
	total_nodes++;
	if(t_sum==0)
	{
		printSubset(t,t_size);
		subsetSum(s,t,s_size,t_size+1,itr+1,t_sum-s[itr]);
	}
	else
	{
		for(int i=itr;i<s_size;i++)
		{
			if(t_sum-s[i]>=0)
			{
				t[t_size]=s[i];
				subsetSum(s,t,s_size,t_size,itr+1,t_sum-s[i]);
			}
		}
	}
}
int main()
{
	int setSize;
	cin>>setSize;
	int sum;
	cin>>sum;
	int a[setSize];
	for(int i=0;i<setSize;i++)
		cin>>a[i];
	int t[setSize];
	subsetSum(a,t,setSize,0,0,sum);
}