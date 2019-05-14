#include<bits/stdc++.h>

using namespace std;

int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l+1;
	int j=h;
	while(i<j)
	{
		do
			i++;
		while(a[i]<=pivot);
		do
			j--;
		while(a[j]>pivot);
		if(i<j)
			a[i]=(a[i]+a[j])-(a[j]=a[i]);
	}
	a[l]=a[j];
	a[j]=pivot;
	return j;
}
void qsort(int a[],int l,int h)
{
	if(l<h)
	{
		int j=partition(a,l,h);
		qsort(a,l,j);
		qsort(a,j+1,h-1);
	}
}
int main()
{
	int a[5]={3,2,4,1,0};
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	qsort(a,0,4);
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}
