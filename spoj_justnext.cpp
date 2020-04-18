#include <iostream>
#include<algorithm>
using namespace std;
string lexicographic(string s)
{
	int n=s.length();
	int j=n-2,k;
	while(s[j]>=s[j+1]&&j>=0)
		j--;
	if(j==-1)
		return "-1";
	k=n-1;
	while(s[j]>=s[k])
		k--;
	swap(s[j],s[k]);
	int r=n-1;
	//scout<<"Hello\n";
	int q=j+1;
	while(q<r)
	{
		swap(s[q],s[r]);
		q++;
		r--;
	}
	return s;
	
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s="";
		while(n--)
		{
			char ch;
			cin>>ch;
			s+=ch;
		}

		s=lexicographic(s);
		cout<<s<<"\n";
		
	}
	return 0;
}