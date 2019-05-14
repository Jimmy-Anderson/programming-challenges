#include<bits/stdc++.h>

using namespace std;

int main()
{
	//int V[]={1,2,5,10,20,50,100,500,1000};
	//int n=93;
	int V[]={1,5,6,9};
	int n=11;
	int m=sizeof(V)/sizeof(V[0]);
	cout<<"Given amount="<<n<<"\n";
	cout<<"Denominations are\n";
   
	int table[n+1][2];
	table[0][0]=table[0][1]=0;
	for(int i=1;i<=n;i++)
		table[i][0]=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(V[j]<=i)
			{
				int res=table[i-V[j]][0];
				if(res!=INT_MAX&&(res+1)<table[i][0])
				{
					table[i][0]=res+1;
					table[i][1]=V[j];
				}
			}
		}
	}
	cout<<"Minimum number of coins required is "<<table[n][0]<<"\n";
    int i=n;
	int ref=n;
	int ref2=table[n][1];
	cout<<"Denominations are\n";
	while(ref)
	{
		cout<<ref2<<" ";
		ref=ref-ref2;
		ref2=table[ref][1];
		if(ref==ref2)
		{			
			cout<<ref2<<" ";
			break;
		}
	} 
	cout<<"\n";
}
