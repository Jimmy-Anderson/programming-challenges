#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;   cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int gcd(int a,int b){
    if(b==0)
            return a;
    else
        return gcd(b,a%b);
}
int getCount(int x,int y){
    int lcm=(x*y)/gcd(x,y);
    int count=lcm-y;
    return count;
}
lli getVal(lli n,int x,int y,int lcm,int count){
    if(n==0)
        return 0;
    lli sum=count*(n/lcm);
    lli i=n%lcm;
    sum+=(lcm-max(i,(lli)y));
    return sum;

}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        int a,b,q,x,y;
        cin>>a>>b>>q;
        x=min(a,b);
        y=max(a,b);
        while(q--){
            int l,r;
            cin>>l>>r;
            if(a==b){
                cout<<"0\n";
            }
            else{
                int lcm=a*b/gcd(a,b);
                int count=getCount(x,y);
                // cout<<getVal(r,x,y,lcm,count)<<"\n";
                // cout<<getVal(l-1,x,y,lcm,count)<<"\n";
                cout<<getVal(r,x,y,lcm,count)-getVal(l-1,x,y,lcm,count)<<"\n";
            }
        }


    }
}
