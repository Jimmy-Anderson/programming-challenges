#include<bits/stdc++.h>
#define lli long long int
#define rep(a,b,c) for(long long int i=a;i<b;i+=c)
#define repd(a,b,c) for(long long int i=a;i>=b;i-=c)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

typedef struct Node
{
	int data;
	int index;
	struct Node* next;
}node;

node* newnode(int data,int index)
{
	node* x=(node*)malloc(sizeof(node));
	x->data=data;
	x->index=index;
	x->next=NULL;
	return x;
}
node* enqueue(node** last,int data,int index)
{
	node *x=newnode(data,index);
	if((*last)==NULL)
	{
		(*last)=x;
		(*last)->next=x;
	}
	else
	{
		x->next=(*last)->next;
		(*last)->next=x;

	}
}
void delete_node(node* cur,node* key)
{
	node* prev=cur;
	while(prev->next!=key)
		prev=prev->next;
	if(cur==key)
	{
		free(key);
	}
	else
	{
		prev->next=key->next;
		free(key);
	}
}

int main()
{
	int n,x;
	cin>>n>>x;
	node* last=NULL;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		enqueue(&last,num,i);
	}
	int k=x;
	node *start,*cur,*maxp;
	start=last->next;
	while(k--&&last->next!=last)
	{
		cur=maxp=start;
		int j=x;
		int max=0;
		while(j--&&last->next!=last)
		{
			if(cur->data>max)
			{
				max=cur->data;
				maxp=cur;
			}
			cur=cur->next;
		}
		cout<<maxp->index<<" ";
		while(start!=cur)
		{
			if(start!=maxp&&start->data!=0)
				(start->data)=start->data-1;
			start=start->next;
		}
		delete_node(last,maxp);
	}
	cout<<last->data<<"\n";
}