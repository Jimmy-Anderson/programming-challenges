#include <bits/stdc++.h> 
using namespace std; 

int dayofweek(int d, int m, int y) 
{ 
	static int t[] = { 0, 3, 2, 5, 0, 3, 
					5, 1, 4, 6, 2, 4 }; 
	y -= m < 3; 
	return ( y + y / 4 - y / 100 + 
			y / 400 + t[m - 1] + d) % 7; 
} 

// Driver Code 
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m1,m2,y1,y2;
        cin>>m1>>y1>>m2>>y2;
        int count=0;
        for(int i=y1;i<=y2;i++)
        {
            if(m1>2&&i==y1)
                continue;
            else if(m2<2&&i==y2)
                continue;
            int day=dayofweek(1,2,i);
            if(day==6)
            {
                count++;
            }
            else if(day==0)
            {
                if(i%400==0||(i%4==0&&i%100!=0))
                    continue;
                count++;
            }
            //cout<<i<<" "<<count<<" "<<day<<"\n";
            if(y1==y2)
                break;
        }
        cout<<count<<"\n";
    } 


	return 0; 
} 