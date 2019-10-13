#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
int countn(int a[],int b[], int m, int n) 
{ 
    // If both first and second string is empty, 
    // or if second string is empty, return 1 
    if ((m == 0 && n == 0) || n == 0) 
        return 1; 
  
    // If only first string is empty and second 
    // string is not empty, return 0 
    if (m == 0) 
        return 0; 
  
    // If last characters are same 
    // Recur for remaining strings by 
    // 1. considering last characters of both strings 
    // 2. ignoring last character of first string 
    if (a[m - 1] == b[n - 1]) 
        return countn(a, b, m - 1, n - 1);
    else
        // If last characters are different, ignore  
        // last char of first string and recur for  
        // remaining string 
        return countn(a, b, m - 1, n)+countn(a,b,m,6); 
} 
int main()
{
	
    int m;
    cin>>m;
    int a[m];
    rep(i,0,m)
    	cin>>a[i];
    int n=6;
    int b[6]={4,8,15,16,23,42};
  	int count=0;
    // Create a table to store results of sub-problems 
    for(int i=0;i<m;i++)
    {
    	int k=0;
    	for(int j=0;j<m;j++)
    	{
    		if(a[j]==b[k])
    		{
    			a[j]=-1;
    			k++;
    		}
    	}
    	if(k==6)
    		count++;
    }
    cout<<(m-6*count)<<"\n";
}