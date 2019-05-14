#include<bits/stdc++.h>

using namespace std;
int treasure_max(int i,int j,int t[5][5])
{
	if(i==0&&j==0)
		return t[0][0];
	else
	{
		if(i-1>=0&&j-1>=0)
			return (max(treasure_max(i-1,j,t)+t[i][j],treasure_max(i,j-1,t)+t[i][j]));
		else if(i-1>=0)
			return (treasure_max(i-1,j+1,t)+t[i][j]);
		else if(j-1>=0)
			return (treasure_max(i+1,j-1,t)+t[i][j]);
		else
			return 0;
	}
}
int main()
{
	int t[5][5]={{4,8,3,6,1},{9,7,2,5,11},{5,9,2,4,1},{7,1,3,6,5},{4,1,2,4,5}};
	int sum=treasure_max(4,4,t);
	cout<<sum<<"\n";
}
