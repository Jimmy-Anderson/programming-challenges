/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
void push_digits(string num,set<int>&dig)
{
    for(int i=0;i<num.length();i++)
    {
        int d=num[i]-'0';
        dig.insert(d);
    }
}
bool check_digits(string num,set<int>&dig)
{
    for(int i=0;i<num.length();i++)
    {
        int d=num[i]-'0';
        if(dig.find(d)!=dig.end())
            return 0;
    }
    return 1;
}
int main(int argc, char *a[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        vector<string>a;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            a.push_back(s);
        }
        sort(a.begin(),a.end());
        long long int max_sum=0;
        for(int i=n-1;i>=0;i--)
        {
            set<int>dig;
            push_digits(a[i],dig);
            int x;
            stringstream ss(a[i]);
            ss>>x;
            long long int sum=x;
            for(int j=n-1;j>=0;j--)
            {
                if(i==j)
                    continue;
                if(check_digits(a[j],dig))
                {
                    stringstream ss(a[j]);
                    ss>>x;
                    sum+=x;
                    push_digits(a[j],dig);
                }
            }
            if(sum>max_sum)
                max_sum=sum;
        }
        cout<<max_sum<<"\n";
    }
}
