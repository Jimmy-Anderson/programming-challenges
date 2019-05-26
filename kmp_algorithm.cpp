#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<=b;i++)
#define repd(i,a,b) for(long long int i=a;i>=b;i--)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
void getLPS(int* lps,char *pat,int size)
{
  int len=0;
  lps[0]=0;
  int i=1;
  while(i<size)
  {
    if(pat[i]==pat[len])
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
}
void kmpSearch(char *txt,char *pat)
{
  int n=strlen(txt);
  int m=strlen(pat);
  int i=0,j=0;
  int lps[m];
  getLPS(lps,pat,m);
  while(i<n)
  {
    if(txt[i]==pat[j])
    {
        i++;j++;
    }
    if(j==m)
    {
      cout<<"Pattern found at the position:"<<i-j<<"\n";
      j=lps[j-1];//update j
    }
    else if(txt[i]!=pat[j])
    {
      if(j!=0)
        j=lps[j-1];
      else
        i++;
    }
  }
}
int main()
{
  string txt;
  string pattern;
  cin>>pattern;
  cin>>txt;
  char txt2[txt.length()+1];
  char pattern2[pattern.length()+1];
  strcpy(txt2,txt.c_str());
  strcpy(pattern2,pattern.c_str());
  kmpSearch(txt2,pattern2);
}
