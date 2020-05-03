#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
void compute_permutation(vector<int>&A,int n,int depth,int used[],vector<int>&current,vector<vector<int>>&ans)
{
    if(depth==n)
    {
        ans.push_back(current);
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(!used[i])
            {
                current.push_back(A[i]);
                used[i]=1;
                compute_permutation(A,n,depth+1,used,current,ans);
                current.pop_back();
                used[i]=0;

            }
        }
    }
}
vector<vector<int> > permute(vector<int> &A) {
    int n=A.size();
    int used[n];
    for(int i=0;i<n;i++)
        used[i]=0;
    vector<int>current;
    vector<vector<int>>ans;
    compute_permutation(A,n,0,used,current,ans);
    return ans;
}
int main()
{
  int n;
  cout<<"Enter size of array\n";
  cin>>n;
  vector<int>arr(n);
  cout<<"Enter the elements of array\n";
  rep(i,0,n-1)
    cin>>arr[i];
  vector<vector<int>>ans;
  ans=permute(arr);
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
      cout<<ans[i][j];
    cout<<"\n";
  }
}
