#include<bits/stdc++.h>
#define rep1(a,b) for(int i=a;i<b;i++)
#define rep2(a,b) for(int j=a;j<b;j++)
#define rep3(a,b) for(int k=a;k<b;k++)
using namespace std;
int main()
{
    int p,q,r,i,j,k,rmax=0,cmax=0,sr,sc;
    cin>>p>>q;
    int a[p][q];
    rep1(0,p)
    	rep2(0,q)
    		cin>>a[i][j];
    cin>>q>>r;int b[q][r],c[p][r];
    rep1(0,q)
    	rep2(0,r)
    		cin>>b[i][j];
    rep1(0,p)
    	rep2(0,r)
    	{
    		c[i][j]=0;
    		rep3(0,q)
    			c[i][j]+=a[i][k]*b[k][j];
    	}
    rep1(0,p)
    {
    	sr=0;
    	rep2(0,r)
    		sr=sr+c[i][j];
    	if(sr>rmax)
    		rmax=sr;
    }
    rep1(0,r)
    {
    	sc=0;
    	rep2(0,p)
    		sc=sc+c[j][i];
    	if(sc>cmax)
    		cmax=sc;
    }
    cout<<max(rmax,cmax);
}