#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(i=a;i<=b;i++)
int i,j=1,c,k;
void sleep(int k)
{
	for(c=1;c<=k;c++,j++)
		if(j%7==5||j%7==6)
			cout<<c<<"."<<i<<".2019\n";
}
int main()
{
	rep(1,12)
	{
		if((i%2!=0&&i<=7)||(i%2==0&&i>7))
			sleep(31);
		else if(i==2)
			sleep(28);
		else 
			sleep(30);
	}
}