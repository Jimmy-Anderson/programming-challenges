#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
/*
	question
	The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/
int main()
{
	int A;
	cin>>A;
	string num="1";
    for(int i=2;i<=A;i++)
    {
        string new_num;
        int count=1,j;
        for(j=0;j<num.length()-1;j++)
        {
            if(num[j]==num[j+1])
                count++;
            else
            {
                new_num=new_num+ to_string(count);
                new_num.push_back(num[j]);
                count=1;
            }
        }
        new_num=new_num+ to_string(count);
        new_num.push_back(num[j]);
        num=new_num;
    }
    cout<<num<<"\n";
}
