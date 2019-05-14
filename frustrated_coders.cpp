#include<bits/stdc++.h>
# define lli long long int
using namespace std;
lli n;
void kill (lli a[],lli i,lli j)
{
    if(j==n)
        return;
    else
    {
        if(a[i]<a[j])
        {
            a[i]=0;
            kill(a,i+1,j+1);
		}
		else
			kill(a,i,j+1);    
    }
}
int main()
{
	cin>>n;
	lli x[n];
	for(lli i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	kill(x,0,1);
	lli sum=0;
	for(lli i=0;i<n;i++)
	{
	    sum+=x[i];
	}

	cout<<sum<<"\n";
}