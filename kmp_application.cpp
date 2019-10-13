/*
SMALLEST repetitive SUBSTRING IN A STRING
write the length of smallest substring that repeats through the string
*/
#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
    test()
    {
        string s;
        cin>>s;
        int l=s.length();
        int lps[l];
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<l)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                    len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        //len=lps[l-1]
        //check whether a repetitive string exists or not
        //l%(l-len)==0 then yes
        if(l%(l-len)==0)
        {
            //repetitive string exists
            cout<<(l-len)<<"\n";
        }
        else
            cout<<l<<"\n";
    }
}
