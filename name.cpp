#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
void sieve(int n,vector<bool>&prime)
{
    for(int i=0;i<=n;i++)
        prime.push_back(true);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(prime[j]==true)
                    prime[j]=false;
            }
        }
    }
}
int main()
{
    vector<bool>prime;
    sieve(128,prime);
    vector<int>set;
    for(int i=0;i<prime.size();i++)
    {
      if(prime[i]==true)
        set.push_back(i);
    }
    int setsize=set.size();
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      string s;
      cin>>s;
      for(int i=0;i<n;i++)
      {
        char c=s[i];
        int x=(int)c;
        int d,pos;
        d=abs(x-set[0]);
        pos=0;
        for(int j=1;j<setsize;j++)
        {
          if(abs(x-set[j])<d)
          {
            d=abs(x-set[j]);
            pos=j;
          }
        }
        s[i]=(char)set[pos];
      }
      cout<<s<<"\n";
    }
}
