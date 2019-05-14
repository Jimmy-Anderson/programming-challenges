#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;
char check_duplicates(vector<int>&arr,int start,int end)
{
	int start2=arr[start+1];
	int end2=arr[end-1];
	if(start2>end2)
		return 'R';
	else
		return 'L';
}
int main()
{
	int n,num;
	cin>>n;
	vector<int> arr;
	vector<int>sequence;
	vector<char>moves;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		arr.push_back(num);
	}
	int start=0,end=n-1;
	if(arr[start]<arr[end])
	{
		sequence.push_back(arr[start]);
		moves.push_back('L');
		start++;
	}
	else if(arr[start]>arr[end])
	{
		sequence.push_back(arr[end]);
		moves.push_back('R');
		end--;
	}
	else
	{
		char c=check_duplicates(arr,start,end);
		if(c=='R')
		{
			sequence.push_back(arr[end]);
			moves.push_back('R');
			end--;
		}
		else
		{
			sequence.push_back(arr[start]);
			moves.push_back('L');
			start++;
		}
	}
	while(start<=end)
	{
		int key=sequence[sequence.size()-1];
		if(arr[start]<key&&arr[end]<key)
			break;
		else if(arr[start]>key&&arr[end]>key)
		{
			if(arr[start]<arr[end])
			{
				sequence.push_back(arr[start]);
				moves.push_back('L');
				start++;
			}
			else if(arr[start]>arr[end])
			{
				sequence.push_back(arr[end]);
				moves.push_back('R');
				end--;
			}
			else
			{
				char c=check_duplicates(arr,start,end);
				if(c=='R')
				{
					sequence.push_back(arr[end]);
					moves.push_back('R');
					end--;
				}
				else
				{
					sequence.push_back(arr[start]);
					moves.push_back('L');
					start++;
				}
			}
		}
		else if(arr[start]<key&&arr[end]>key)
		{
			sequence.push_back(arr[end]);
			moves.push_back('R');
			end--;
		}
		else if(arr[start]>key&&arr[end]<key)
		{
			sequence.push_back(arr[start]);
			moves.push_back('L');
			start++;
		}
	}
	cout<<moves.size()<<"\n";
	for(int i=0;i<moves.size();i++)
		cout<<moves[i];
}
