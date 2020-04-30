#include<bits/stdc++.h>
#define n 10
void printboard(bool table[n][n])
{
	static int k=1;
	std::cout<<" "<<k++<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			std::cout<<table[i][j]<<" ";
		std::cout<<"\n";
	}
}
bool checkAttack(bool table[n][n],int row,int col)
{
	for(int i=0;i<row;i++)
		if(table[i][col])
			return false;
	for(int i=row,j=col;i>=0&&j<n;i--,j++)
		if(table[i][j])
			return false;
	for(int i=row,j=col;i>=0&&j>=0;i--,j--)
		if(table[i][j])
			return false;
	return true;
}
bool solve(bool table[n][n],int row)
{
	if(row>=n)
	{
		std::cout<<"Solution is\n";
		printboard(table);
		return true;
	}
	bool res=false;
	for(int j=0;j<n;j++)
	{
		if(checkAttack(table,row,j))
		{
			table[row][j]=true;
			res=solve(table,row+1)||res;
			table[row][j]=false;
		}
	}
	return res;
}
void backtrackSolve()
{
	bool table[n][n];
	memset(table,false,sizeof(table));
	if(!solve(table,0))
	{
		std::cout<<"No Solutions exists\n";
		return;
	}
	return;
}

int main()
{
	backtrackSolve();
	return 0;
}
