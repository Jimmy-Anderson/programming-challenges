#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;    cin>>t;    while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
void multiply(lli a[4][4],lli b[4][4])
{
    lli c[4][4];
    lli i=0,j=0,k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            c[i][j]=0;
            for(k=0;k<4;k++)
                c[i][j]=(c[i][j]%mod+(a[i][k]%mod*b[k][j]%mod)%mod)%mod;
        }
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            a[i][j]=c[i][j];
}

lli matrix_exp(lli f[4][4],lli n)
{
    lli m[4][4]={{2,-1,0,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}};
    if(n==1)
        return (6*f[0][0]%mod+3*f[0][1]%mod+1*f[0][2]%mod+1*f[0][3]%mod)%mod;
    matrix_exp(f,n/2);
    multiply(f,f);
    if(n&1)
        multiply(f,m);
        return (6*f[0][0]%mod+3*f[0][1]%mod+1*f[0][2]%mod+1*f[0][3]%mod)%mod;
}
lli findnthterm(lli n)
{
    lli F[4][4]={{2,-1,0,1},{1,0,0,0},{0,1,0,0},{0,0,0,1}};
    return matrix_exp(F,n-3);
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
        else if(n==2)
            ans=2;
        else if(n==3)
            ans=6;
        else
            ans=findnthterm(n);
        cout<<ans<<"\n";
    }
}