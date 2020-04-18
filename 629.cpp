#include <bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string x;
        cin>>x;
        string a,b;
        for(int i=0;i<n;i++)
        {
            if(i==0){
                a.push_back('1');
                b.push_back('1');
            }
            else
            {
                if(x[i]=='2'){
                    a.push_back('0');
                    b.push_back('2');

                }
                else if(x[i]=='1'){
                    a.push_back('0');
                    b.push_back('1');
                }
                else if(x[i]=='0'){
                    a.push_back('0');
                    b.push_back('0');
                }
            }
        }
        cout<<b<<"\n"<<a<<"\n";
    }
}