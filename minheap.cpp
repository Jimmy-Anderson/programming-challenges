#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

void swap(int *x,int *y)
class MinHeap
{
	int *harr;
	int capacity;
	int cur_size;

	MinHeap(int capacity);

	void MinHeapify(int i);

	int parent(int i)
		return (i-1)/2;
	int left(int i)
		return 2*i+1;
	int right(int i)
		return 2*i+2;
	int extractMin();
	
	void decreaseKey(int i,int new_val);

	int getMin()
	{
		return harr[0];
	}

	void deleteKey(int i);

	void insertKey(int k)	

}

MinHeap::MinHeap(int cap)
{
	cur_size=0;
	capacity=cap;
	harr=new int[cap];
}

void MinHeap::insertKey(int k)
{
	if(cur_size==capacity)
		return;
	// Overflow occurs
	cur_size++;
	int i=cur_size-1;
	harr[i]=k;

	//Heapify
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i=parent(i);
	}
}

void MinHeap::decreaseKey(int i,int new_val)
{
	harr[i]=new_val;
	while(i!=0&&harr[parent(i)]>harr[i])
	{
		swap(&harr[i],&harr[parent(i)]);
		i=parent(i);
	}
}

int MinHeap::extractMin()
{
	if(cur_size<=0)
		return INT_MAX;
	if(cur_size==1)
	{
		cur_size--;
		return harr[0];
	}
	int root=harr[0];
	harr[0]=harr[cur_size-1];
	cur_size--;
	MinHeapify(0);
	return root;
}
void MinHeap::deleteKey(int i)
{
	decreaseKey(i,INT_MIN);
	extractMin();
}
void MinHeap::MinHeapify(int i)
{
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<cur_size&&harr[l]<harr[i])
			smallest=l;

	if(r<cur_size&&harr[r]<harr[i])
			smallest=r;
	if(smallest!=i)
	{
		swap(&harr[i],&harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(int *x,int *y)
{
	*x=(*x+*y)-(*y=*x);
}
int main()
{
	
}