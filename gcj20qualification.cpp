#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;


void invert(vector<int>&arr){
	for(int i=1;i<arr.size();i++){
		if(arr[i]!=-1){
			arr[i]=!arr[i];
		}
	}
}
void reverse(vector<int>&arr){
	int i=1,j=arr.size()-1;
	while(i<j){
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
}
void print(vector<int>&arr){
	string output;
	for(int i=0;i<arr.size();i++){
		output+=(arr[i]+'0');
	}
	cout<<output;
	cout.flush();

}
int verify(vector<int>&unchange,vector<int>&rev,vector<int>&inv,vector<int>&invrev,int b){
	bool check[4]={0};
	for(int steps=1;steps<=10;steps++){
		int i=(rand()%b)+1;
		cout<<i;
		cout.flush();
		int val;
		cin>>val;
		if(steps%10!=1){
			if(val==unchange[i])
				check[0]++;
			if(val==rev[i])
				check[1]++;
			if(val==inv[i])
				check[2]++;
			if(val==invrev[i])
				check[3]++;
		}
		else{
			reverse(inv.begin(),inv.end());
			reverse(invrev.begin(),invrev.end());
			invert(inv);
			invert(invrev);
			if(val==unchange[i])
				check[0]++;
			if(val==rev[i])
				check[1]++;
			if(val==inv[i])
				check[2]++;
			if(val==invrev[i])
				check[3]++;
		}
	}
	int maxval=-1,maxi=1;
	for(int i=0;i<4;i++){
		if(check[i]>maxval){
			maxval=check[i];
			maxi=i;
		}
	}
	return maxi+1;
}
int main() {
	srand(time(NULL));
    int t;
    cin>>t;
    while(t--){
    	int b;
    	cin>>b;
    	vector<int>unchange(b+1,-1);
    	vector<int>rev(b+1,-1);
    	vector<int>inv(b+1,-1);
    	vector<int>invrev(b+1,-1);
    	for(int i=1;i<=b;i++){
    		cout<<i;
    		int val;
    		cin>>val;
    		cout.flush();
    		if(i%10!=1){
    			unchange[i]=val;
    			rev[i]=val;
    			inv[i]=val;
    			invrev[i]=val;
    		}
    		else{
    			reverse(inv);
    			reverse(invrev);
    			invert(inv);
    			invert(invrev);
    			unchange[i]=val;
    			rev[i]=val;
    			inv[i]=val;
    			invrev[i]=val;
    		}
    	}
    	int steps=(b+1)%10,ans;
    	if(steps==1){
    		ans=verify(unchange,rev,inv,rev,b);
    	}
    	else{
    		int diff=11-steps;
    		for(int i=1;i<diff;i++){
    			cout<<i;
	    		cout.flush();
	    		int val;
	    		cin>>val;
    		}
    		ans=verify(unchange,rev,inv,rev,b);
    	}
    	if(ans==1)
    		print(unchange);
    	else if(ans==2)
    		print(rev);
    	else if(ans==3)
    		print(inv);
    	else if(ans==4)
    		print(invrev);
    	char ch;
    	cin>>ch;
    	if(ch=='N')
    		break;
    	else 
    		continue;

    }
    return 0;
}