#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

lli gcdExtended(lli a, lli b, lli *x, lli *y); 
  
// Function to find modulo inverse of a 
lli modInverse(lli a, lli m) 
{ 
    lli x, y; 
    lli g = gcdExtended(a, m, &x, &y); 
    lli res;
    if (g != 1) 
        res=-1;
    else
    { 
        // m is added to handle negative x 
        res = (x%m + m) % m; 
    }
    return res;

} 
  
// C function for extended Euclidean Algorithm 
lli gcdExtended(lli a, lli b, lli *x, lli *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    lli x1, y1; // To store results of recursive call 
    lli gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
lli fast_exp(lli n,lli m)
{
    lli result=1;
    while(m>0)
    {
        if(m&1)
            result=(result*n)%mod;
        n=(n*n)%mod;
        m=m/2;
    }
    return result;
}
lli gcd(lli a,lli b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
void addition(lli a,lli b,lli c,lli d,lli f[2])
{
    f[0]=a*d+b*c;
    f[1]=b*d;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        lli n,k,m;
        cin>>n>>k>>m;
        if(m&1)
        {
            lli x=fast_exp(n,m/2+1);
            lli y=fast_exp(n-1,m/2+1);
            lli num=x-y;
            lli den=x;
            lli res=(num%mod*modInverse(den,mod))%mod;
            cout<<(res+mod)%mod<<"\n";
       }
       else
       {
            lli y=fast_exp(n,m/2);
            lli x=fast_exp(n-1,m/2);
            lli num=((n+k)*(y-x))+x;
            lli den=y*(n+k);
            lli res=(num%mod*modInverse(den,mod))%mod;
            cout<<(res+mod)%mod<<"\n";
        }
    }
}