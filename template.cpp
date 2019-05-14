#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=a1;i>=b;i)
#define nl          cout<<endl;
#define test()      lli t;cin>>t;while(t--)
#define sp(n)       setprecision(n)
 
#define lli     long long int
#define ulli    unsigned long long int
#define ld      long double
#define uld     unsigned long double
#define S       string
#define C       char
#define elif    else if
 
#define push    push_back
#define pop     pop_back
#define plli    pair<lli,lli>
#define vlli    vector<lli>
#define vulli   vector<ulli>
#define vld     vector<ld>
#define vs      vector<string>
 
#define bs      binary_search
#define ub      upper_bound
#define lb      lower_bound
 
#define vsort(v) sort(v.begin(),v.end())
 
#define max1 1000001
#define max2 10000001
#define max3 1000000007
#define inf  1000000009
 
lli gcd(lli a, lli b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
 
lli lcm(lli x,lli y)
{
    return ((x*y)/gcd(x,y));
}
 
 
bool prime(lli n)
{
    if(n==1)
        return false;
    if(n==2)
        return true;
    lli k=sqrt(n)+1;
    rep(i,2,k)
        if(n%i==0)
            return false;
    return true;
}
 
lli modpow(lli x, lli y, lli p)
{
    lli res = 1;
 
    x = x % p;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
 
lli power(lli x, lli n)
{
    if(n==0)
     return 1;
    if(n%2==0)
        return power(x*x,n/2);
    else
        return x*power(x,n-1);
}
 
 