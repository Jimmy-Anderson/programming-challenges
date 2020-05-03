#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int main()
{ 
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        int pos[n+1]={0};
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=n)
                pos[a[i]]=i+1;
        }
        int i;
        map<int,int>mp;
        for( i=0;i<n;i++){
            if(a[i]>n||mp[a[i]]>1)
                break;
            mp[a[i]]++;
        }
        if(i<n){
            cout<<"No\n";
            continue;
        }
        if(n==1||n==2){
            cout<<"Yes\n";
            continue;
        }
        int t=-1,flag=1;
        int visited[n+1]={0};
        for(int i=1;i<=n;i++){
            if(t==n+1){
                t=-1;
            }
            if(t==-1){
                visited[pos[i]]=1;
                t=pos[i]+1;
                continue;
            }
            if(visited[t]==1){
                t=pos[i]+1;
                visited[pos[i]]=1;
                continue;
            }
            if(t!=pos[i]){
                flag=0;
                break;
            }
            visited[pos[i]]=1;
            t++;
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}