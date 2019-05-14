#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int l=s.length();

    int a[l+1];
    for(int i=l-1;i>=0;i--)
    {
        char c=s.at(i);
        int ch;
        ch=(int)c-(int)'0';
        if(ch%2==0&&i==l-1)
            a[l]=1;
        else if(ch%2!=0&&i==l-1)
            a[l]=0;
        else if(ch%2==0&&i!=l-1)
            a[i+1]=a[i+2]+1;
        else if(ch%2!=0&&i!=l-1)
            a[i+1]=a[i+2];
    }
    for(int i=1;i<=l;i++)
        cout<<a[i]<<" ";
	
}