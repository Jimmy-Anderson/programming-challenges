#include<bits/stdc++.h>
using namespace std;
int n;
bool floodfill_algorithm(int i,int j,int visited[20][20], int a[20][20])
{
    if(i<0||j<0||i>=n||j>=n)
        return false;
    if(visited[i][j])
        return false;
    visited[i][j]=true;
    if(a[i][j]==3)
        return false;
    else if(a[i][j]==2)
        return true;
    else
    {
        bool x=floodfill_algorithm(i+1,j,visited,a);
        bool y=floodfill_algorithm(i-1,j,visited,a);
        bool z=floodfill_algorithm(i,j+1,visited,a);
        bool w=floodfill_algorithm(i,j-1,visited,a);
        return x||y||z||w;
    }
}
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         cin>>n;
         int a[20][20];
         int visited[20][20];
         int srci,srcj;
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==1)
                {
                    srci=i;
                    srcj=j;
                }
            }
        }
        memset(visited,0,sizeof(visited));
        if(floodfill_algorithm(srci,srcj,visited,a))
            cout<<"1\n";
        else
            cout<<"0\n";

     }

	//code
	return 0;
}
