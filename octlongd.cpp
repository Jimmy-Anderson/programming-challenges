#include<bits/stdc++.h>
using namespace std;
void modifyMap(int n, unordered_map<int,int>&mp)
{
	for (int i=1; i<=sqrt(n); i++) 
	{ 
        if (n%i == 0) 
        {
            if (n/i == i)
            {
            	if(mp.find(i)==mp.end())
            		mp[i]=1;
            	else
            		mp[i]++;
            }  
            else
            {
                if(mp.find(i)==mp.end())
            		mp[i]=1;
            	else
            		mp[i]++;
            	if(mp.find(n/i)==mp.end())
            		mp[n/i]=1;
            	else
            		mp[n/i]++;
            }
        } 
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>a(n);
		vector<int>star(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		unordered_map<int,int>mp;
		int maxval=0;
		for(int i=0;i<n;i++)
		{
			modifyMap(a[i],mp);
			star[i]=mp[a[i]]-1;
			maxval=max(maxval,star[i]);
		}
		cout<<maxval<<"\n";    	
	}
}