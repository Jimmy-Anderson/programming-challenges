#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}node;
node* newnode(int data)
{
	node* test=(node*)malloc(sizeof(node));
	test->data=data;
	test->next=NULL;
	return test;
}
int main()
{
	test()
	{
		int n;
		cin>>n;
		string s;
		int a[5]={0};
		int freq[32]={0};
		while(n--)
		{
			cin>>s;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]=='a')
					a[4]=1;
				if(s[i]=='e')
					a[3]=1;
				if(s[i]=='i')
					a[2]=1;
				if(s[i]=='o')
					a[1]=1;
				if(s[i]=='u')
					a[0]=1;
			}
			int num=0;
			for(int i=4;i>=0;i--)
				if(a[i]==1)
					num=num+pow(2,i);
			freq[num]++;
			for(int i=4;i>=0;i--)
				a[i]=0;
		}
		lli total=0;
		for(int i=0;i<31;i++)
		{
			for(int j=i+1;j<32;j++)
			{
				if((i|j)==31)
				{
					total=total+freq[i]*freq[j];
				}
			}
		}
		if(freq[31]>1)
		total+=((freq[31]*(freq[31]-1))/2);
		cout<<total<<"\n";
	}
}