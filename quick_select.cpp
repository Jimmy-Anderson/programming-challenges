#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l+1;
	int j=h;
	do
		i++;
	while(a[i]<=pivot);
	do
		j--;
	while(a[j]>pivot);
	a[l]=a[j];
	a[j]=pivot;
	return j;
}
int select1(int a[],int n,int k)
{
	int l=0;
	int h=n;
	a[n]=INT_MAX;
	while(true)
	{
		int j=partition(a,l,h);
		if(k==j)
			return a[j];
		else if(k<j)
			h=j;
		else if(k>j)
			l=j+1;
	}

}
int main()
{
	int a[]={3,44,55,23,31,65,78,97};
	int n=sizeof(a)/sizeof(int);
	int j=select1(a,n,4);//check 4th maximum
	cout<<j<<"\n";
	sort(a,a+n);//check for correct output;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}