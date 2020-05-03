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
    int te=1;
    test(){
        int u;
        cin>>u;
        set<char>possible;
        map<char,set<int>>dig;
        vector<char>res(10,-1);
        vector<pair<string,string>>vec(10000);
        for(int i=0;i<10000;i++){
            string q,r;
            cin>>q>>r;
            vec[i].first=q;
            vec[i].second=r;
        }
        sort(vec.begin(),vec.end());
        int c=0;
        for(int i=0;i<10000;i++){
            string q,r;
            q=vec[i].first;
            r=vec[i].second;
            for(int k=0;k<r.length();k++)
                possible.insert(r[k]);
            if(q=="-1"){
                c++;
                continue;
            }
            int fd=q[0]-'0';
            if(fd==1&&r.length()==u){
                res[1]=r[0];
                dig[r[0]].insert(1);
            }
            else if(r.length()==u){
                int upper=fd;
                if(dig[r[0]].empty()){
                    for(int j=1;j<=fd;j++)
                        dig[r[0]].insert(j);
                }
                else{
                    int upper=*(dig[r[0]].rbegin());
                    if(fd<upper){
                        for(int j=fd+1;j<=upper;j++)
                            dig[r[0]].erase(j);
                    }
                }
            }         
        }
        if(c==10000){
            cout<<"Case #"<<te++<<": ";
            for(auto num:possible)
                cout<<num;
            cout<<"\n";   
            continue; 
        }
        for(auto x:possible){
            if(dig.find(x)==dig.end()){
                res[0]=x;
            }
        }
        for(auto itr=dig.begin();itr!=dig.end();itr++){
            res[itr->second.size()]=itr->first;
        }
        // for(int i=2;i<10;i++){
        //     for(int j=0;j<i;j++){
        //         dig[i].erase(res[j]);
        //     }
        //         res[i]=*(dig[i].begin());
        // }  
        cout<<"Case #"<<te++<<": ";
        for(auto num:res)
            cout<<num;
        cout<<"\n";
    }

}
