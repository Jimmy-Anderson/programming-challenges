
#include<bits/stdc++.h>
#define lli long long int
#define for(a,b,c) for(int i=a;i<b;i+=c)
#define test() int t;	cin>>t;	while(t--)
#define mod 1000000007
using namespace std;
lli power(lli x, lli y, lli p) 
{ 
    lli res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
int main()
{
	test()
	{
		lli n;
		cin>>n;
		lli ans;
		if(n==1)
			ans=1;
		else
			ans=((n%mod)+((n-1)%mod)*power(2,n-2,mod))%mod;
		cout<<ans<<"\n";
	}
	
}