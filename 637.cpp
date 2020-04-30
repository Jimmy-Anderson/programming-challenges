#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,test;
	cin>>t;
	test=1;
	while(t--){
		int n;
		cin>>n;
		if(n%4==0||n%4==3)
			cout<<"case "<<test++<<": 0\n";
		else
			cout<<"case "<<test++<<": 1\n";
	}
	return 0;
}