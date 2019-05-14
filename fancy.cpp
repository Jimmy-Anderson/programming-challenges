#include<bits/stdc++.h>

using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	cin.ignore(256,'\n');
	while(t--)
	{
		string s;
		getline(cin,s);
		int len=s.length();
		s[len]=' ';
		s[len+1]='\0';
		int flag=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='n'&&s[i+1]=='o'&&s[i+2]=='t'&&s[i+3]==' '&&i==0)
			{
				flag=1;
				break;
			}
			if(s[i]==' '&&s[i+1]=='n'&&s[i+2]=='o'&&s[i+3]=='t'&&s[i+4]==' '&&i!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			cout<<"Real Fancy\n";
		else
			cout<<"regularly fancy\n";
	}
}