#include<bits/stdc++.h>
using namespace std;
typedef struct box{
 int col;
 int num;
 int cap;
}box;

bool comp(box a, box b )
{
    return a.cap<b.cap;
}

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
   int n,m;
   cin>>n>>m;
   vector<box>list(n);
   for(int i=0;i<n;i++)
   {
      list[i].num=i+1;
      list[i].col=i%m;
      cin>>list[i].cap;
   }
   sort(list.begin(),list.end(),comp);

   int mind=INT_MAX;
   vector<int>match(m,0);
   int i=0,j=0,count=0;
   while(j<n)
   {
     while(count!=m&&j<n)
     {
       if(match[list[j].col]==0)
        count++;
       match[list[j].col]++;
       j++;
     }
     if(j==n&&count!=m)
      break;
    while(count==m&&i<j)
    {
      mind=min(mind,list[j-1].cap-list[i].cap);
      match[list[i].col]--;
      if(match[list[i].col]==0)
        count--;
      i++;
    }
   }

   cout<<mind<<endl;
   }
}
