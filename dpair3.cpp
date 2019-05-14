#include<bits/stdc++.h>

#define lli long long int; 
using namespace std;

typedef struct node{
	int index;
	int data;
}node;


void merge(node a[],int start,int mid,int end)
{
        int i=start,j=mid+1,k=0;
        node b[end-start+1];
        while(i<=mid && j<=end)
        {
	        if(a[i].data<=a[j].data)
	        {
	            b[k++].data=a[i++].data;
	            b[k-1].index=a[i-1].index;
	        }
	        else
	        {
	            b[k++].data=a[j++].data;
	            b[k-1].index=a[j-1].index;
	        }
        }
        if(i>mid)
        {
                while(j<=end)
                {
                    b[k++].data=a[j++].data;
                    b[k-1].index=a[j-1].index;
        		}
        }
        if(j>end)
        {
                while(i<=mid)
                {
                    b[k++].data=a[i++].data;
                    b[k-1].index=a[i-1].index;
        		}
        }
        for(i=0;i<end-start+1;i++)
        {
                a[start+i].data=b[i].data;
                a[start+i].index=b[i].index;
        }
}

void mergesort(node a[],int start,int end)
{
        int mid;
        if(start<end)
        {
                mid=(start+end)/2;
                mergesort(a,start,mid);
                mergesort(a,mid+1,end);
                merge(a,start,mid,end);
        }
}

int main()
{
	int n,m;
	cin>>n>>m;
	node a[n];
	node b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i].data;
		a[i].index=i;
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i].data;
		b[i].index=i;
	}
	mergesort(a,0,n-1);
	mergesort(b,0,m-1);
	for(int i=n-1;i>0;i--)
	{
		cout<<a[i].index<<" "<<b[m-1].index<<"\n";
	}
	for(int i=0;i<m;i++)
	{
		cout<<a[0].index<<" "<<b[i].index<<"\n";
	}

}