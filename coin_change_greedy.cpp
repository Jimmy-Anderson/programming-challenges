#include<bits/stdc++.h>

using namespace std;

int main()
{
	//int V[]={1,2,5,10,20,50,100,500,1000};
	//int n=93;
	int V[]={1,5,6,9};
	int n=11;
	int m=sizeof(V)/sizeof(V[0]);
	int x=m;	
	cout<<"Given amount="<<n<<"\n";
	cout<<"Denominations are\n";
	while(n>=0)
	{
		if(V[x-1]<=n)
		{	
			n=n-V[x-1];
			cout<<V[x-1]<<"\n";
			x=m;
		}
		else
			x--;
		if(x<0)
			break;
	}
	 
}
