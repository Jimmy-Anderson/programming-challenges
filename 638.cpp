#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    test(){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        if(n==1){
            cout<<s<<"\n";
            continue;
        }
        set<char>st;
        int i;
        st.insert(s[0]);
        for( i=1;i<k;i++){
            if(st.find(s[i])==st.end())
                break;
        }
        if(i!=k){
            cout<<s[k-1]<<"\n";
        }
        else{
            st.clear();
            int j=k;
            int freq[26]={0};
            for(int i=0;i<n;i++)
                freq[s[i]-'a']++;
            string ans="";
            while(j<n)
            {
                st.insert(s[j]);
                if(st.size()>2)
                    break;
                if(st.find(s[j])==st.end()){
                    int c=0;
                    if(freq[s[j]-'a']%k==0)
                        c=freq[s[j]-'a']/k;
                    else
                        c=freq[s[j]-'a']/k+1;
                    for(int i=1;i<=c;i++)
                        ans+=s[j];
                }
                j++;
            }
            if(st.size()>2)
                cout<<s.substr(k-1,n-k+1)<<"\n";
            else{
                cout<<ans<<"\n";
            }
        }

    }
}