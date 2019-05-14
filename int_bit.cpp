#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
vector<int> maxset(vector<int> &A) {
    int mstart=0;
    int mend=0;
    int start=0;
    int end=0;
    int curr_size=0;
    int max_size=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=0)
        {
            curr_size++;
            end=i;
        }
        else
        {
            if(curr_size>max_size)
            {    
                max_size=curr_size;
                mstart=start;
                mend=end;
            }
            start=i+1;
            curr_size=0;
        }
    }
    vector<int>res;
    for(int i=mstart;i<=mend;i++)
        res.push_back(A[i]);
}

int main()
{
	vector<int>A,res;
	int n;
	cin>>n;
	rep(i,0,n)
	{
		int k;
		cin>>k;
		A.push_back(k);	
	}
	res=maxset(A);
	rep(i,0,res.size())
	{
		cout<<res[i]<<" ";
	}

}