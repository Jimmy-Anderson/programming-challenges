#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

static int total_nodes;
int maxsum;
vector<int>ansarr;
void printAns(vector<int>s)
{
	int l=s.size();
	cout<<l<<"\n";
	for(int i=0;i<l;i++)
		cout<<s[i]<<" ";
	cout<<"\n";
}
void printSubset(int s[],int size)
{
	for(int i=0;i<size;i++)
		cout<<s[i]<<" ";
	cout<<"\n";
}
void storeAns(int t[],int t_size)
{

    vector<int>x(t,t+t_size);
    ansarr=x;
    //printSubset(t,t_size);
}
void subsetSum(pair<int,int> s[],int t[],int s_size,int t_size,int itr,int t_sum,int &ans)
{
	total_nodes++;
	cout<<total_nodes<<"\t";
	if(t_sum>=0&&maxsum-t_sum>ans)
    {
        ans=maxsum-t_sum;
        storeAns(t,t_size);
    }
	if(t_sum==0)
	{
		subsetSum(s,t,s_size,t_size-1,itr+1,t_sum+s[itr].first,ans);
		return;
	}
	else
	{
	    if(itr<s_size&&t_sum-s[itr].first>=0)
        {
            for(int i=itr;i<s_size;i++)
            {
                t[t_size]=i;
                subsetSum(s,t,s_size,t_size+1,i+1,t_sum-s[i].first,ans);
            }
        }

	}
}
bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.first<b.first;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int setSize;
	cin>>maxsum;
	cin>>setSize;
	pair<int,int>a[setSize];
	for(int i=0;i<setSize;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+setSize);
	int t[setSize];
    int ans=0;
	subsetSum(a,t,setSize,0,0,maxsum,ans);
	printAns(ansarr);
}
