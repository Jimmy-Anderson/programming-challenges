#include<bits/stdc++.h>

using namespace std;
int treasure_max(int i,int j,int t[5][5])
{

	int table[5][5];
	memset(table,0,sizeof(table));
	table[0][0]=t[0][0];


	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(i-1>=0&&j-1>=0)
				table[i][j]=(max(table[i-1][j]+t[i][j],table[i][j-1]+t[i][j]));
			else if(i-1>=0)
				table[i][j]=(table[i-1][j]+t[i][j]);
			else if(j-1>=0)
				table[i][j]=(table[i][j-1]+t[i][j]);	
		}
	}
	
	cout<<"Original\n";
	for(int i=4;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
	cout<<"Dynamic\n";

	for(int i=4;i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Path\n";
    vector<pair<int,int>>path;
	path.push_back(make_pair(4,4));
	while(i!=0||j!=0)
	{
		if(i-1>=0&&j-1>=0)
		{
			if(table[i-1][j]>table[i][j-1])
			{
				path.push_back(make_pair(i-1,j));
				i=i-1;
			}
			else
			{
				path.push_back(make_pair(i,j-1));
				j=j-1;			
			}
		}
		else if(i-1>=0)
			path.push_back(make_pair(--i,j));
		else if(j-1>=0)
			path.push_back(make_pair(i,--j));
    }
    map<int,int>::iterator itr;
    for(itr=path.end();itr!=path.begin();itr--)
    	cout<<"("<<itr->first<<","<<itr->second<<")\n";
	return table[4][4];
}
int main()
{
	int t[5][5]={{4,8,3,6,1},{9,7,2,5,11},{5,9,2,4,1},{7,1,3,6,5},{4,1,2,4,5}};
	int sum=treasure_max(4,4,t);
	cout<<sum<<"\n";
}
