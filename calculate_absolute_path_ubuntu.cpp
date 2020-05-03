#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
string simplifyPath(string path) {
    int l=path.length();
    string word="";
    string last_word="";
    stack<string>folderFrame;
    for(int i=1;i<l;i++)
    {
        char ch=path[i];
        if(ch!='/')
            word+=ch;
        else
        {
            if(word=="..")
            {
                if(!folderFrame.empty())
                    folderFrame.pop();
            }
            else if(word==".")
            {
                word="";
                continue;
            }
            else
            {

                last_word=word;
                if(word!="")
                folderFrame.push(word);
            }
            word="";
        }

    }

    //cout<<word<<"\n";
    if(word=="..")
    {
         if(!folderFrame.empty())
             folderFrame.pop();
    }
    else if(word!=".")
    {
        if(word!="")
        folderFrame.push(word);
    }
    string abs_path="";
    if(folderFrame.empty())
        abs_path="/"+last_word;
    while(!folderFrame.empty())
    {
        string folder=folderFrame.top();
        abs_path="/"+folder+abs_path;
        folderFrame.pop();
    }
    return abs_path;
}

int main()
{
  string s;
  cout<<"Enter an path address(without blank space)\n";
  cout<<"e.g-\"/a/./b/../../c\"\n";
  cin>>s;
  cout<<"Absolute Path will be\n";
  cout<<simplifyPath(s)<<"\n";
}
