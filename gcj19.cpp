#include<bits/stdc++.h>
using namespace std;

char query(int n){
    char ch;
    cout<<n<<endl;
    cin>>ch;
    return ch;
}
int main(){
    int t,f;
    cin>>t>>f;
    while(t--){
        vector<int> freq[5];
        string ans;
        vector<int>temp;
        for(int i=1;i<=595;i+=5){
            char ch=query(i);
            freq[ch-'A'].push_back(i);
        }
        int i;
        for(i=0;i<5;i++){
            if(freq[i].size()==23){
                temp=freq[i];
                ans+=i+'A';
                break;
            }
        }
        
        for(int i=0;i<5;i++)
            freq[i].clear();   
        for(int pos:temp){
            char ch=query(pos+1);
            freq[ch-'A'].push_back(pos+1);
        }
        for(i=0;i<5;i++){
            if(freq[i].size()==5){
                temp=freq[i];
                ans+=i+'A';
                break;
            }
        }


        
        for(int i=0;i<5;i++)
            freq[i].clear(); 
        for(int pos:temp){
            char ch=query(pos+1);
            freq[ch-'A'].push_back(pos+1);
        }
        for(i=0;i<5;i++){
            if(freq[i].size()==1){
                temp=freq[i];
                ans+=i+'A';
                break;
            }
        }
      
        char ch=query(temp[0]+1);
        ans+='A';
        ans+=ch;
        int sum=0;
        for(int i=0;i<5;i++)
            sum+=(int)(ans[i]-'A');
        
        ans[3]=(10-sum)+'A';
        
        cout<<ans<<endl;
        
        cin>>ch;
        if(ch=='N')
            break;

    }
}