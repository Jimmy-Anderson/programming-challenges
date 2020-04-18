#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;   cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define max 21
using namespace std;
vector<vector<int>>skill;
vector<vector<bool>>elimination;
int checkElimination(int r,int c,int rmax,int cmax){
    int i=r,j=c,flag=0;
    j--;
    while(j>=0){
        if(skill[i][j]!=-1){
            if(skill[i][j]>skill[r][c])
                flag=1;
            break;
        }
        j--;
    }
    i=r,j=c;
    j++;
    while(j<cmax){
        if(skill[i][j]!=-1){
            if(skill[i][j]>skill[r][c])
                flag=1;
            break;
        }
        j++;
    }
    i=r,j=c;
    i--;
    while(i>=0){
        if(skill[i][j]!=-1){
            if(skill[i][j]>skill[r][c])
                flag=1;
            break;
        }
        i--;
    }
    i=r,j=c;
    i++;
    while(i<rmax){
        if(skill[i][j]!=-1){
            if(skill[i][j]>skill[r][c])
                flag=1;
            break;
        }
        i++;
    }
    elimination[r][c]=flag;
    return flag;
}
void removeElements(int r,int c){
      for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(elimination[i][j])
                skill[i][j]=-1;
        }
}
int main(){
    int t,test=1;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        skill.resize(r,vector<int>(c,-1));
        elimination.resize(r,vector<bool>(c,0));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>skill[i][j];
        int sum=0;
        while(1){
            int eliminator=0;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++){
                    if(skill[i][j]!=-1)
                        eliminator+=checkElimination(i,j,r,c);
                    if(skill[i][j]!=-1)
                        sum+=skill[i][j];
                }

            if(eliminator==0)
                break;
            removeElements(r,c);
            elimination.resize(r,vector<bool>(c,0));
        }
        cout<<"Case #"<<test++<<": "<<sum<<"\n";
    }
}
