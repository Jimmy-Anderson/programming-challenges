#include<bits/stdc++.h>
#define lli long long int
#define rep(i,a,b) for(long long int i=a;i<b;i+=1)
#define repd(i,a,b) for(long long int i=a;i>=b;i-=1)
#define test() int t;	cin>>t;	while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define modval 998244353
using namespace std;
string convertToPostfix	(string s){
	string res="";
	stack<char>st;
	for(int i=0;i<s.length();i++){
		if(s[i]=='#')
			res+=s[i];
		else if(s[i]=='('||s[i]=='&'||s[i]=='^'||s[i]=='|')
			st.push(s[i]);
		else if(s[i]==')'){
			while(!st.empty()&&st.top()!='('){
				char c=st.top();
				st.pop();
				res+=c;
			}
			if(!st.empty())
				st.pop();
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}
 
lli modInverse(lli a, lli m) 
{ 
	lli m0 = m; 
	lli y = 0, x = 1; 

	if (m == 1) 
	return 0; 

	while (a > 1) 
	{ 
		// q is quotient 
		lli q = a / m; 
		lli t = m; 

		// m is remainder now, process same as 
		// Euclid's algo 
		m = a % m, a = t; 
		t = y; 

		// Update y and x 
		y = x - q * y; 
		x = t; 
	} 

	// Make x positive 
	if (x < 0) 
	x += m0; 

	return x; 
} 
int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	lli t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string y=convertToPostfix(s);
		stack<char>st;
		lli num0,den0,num1,den1,numa,dena,numA,denA;
		num0=den0=num1=den1=numa=dena=numA=denA=1;
		if(y.size()==1&&y[0]=='#'){
			lli x=modInverse(4,modval);
			cout<<x<<" "<<x<<" "<<x<<" "<<x<<"\n";
			continue;
		}
		for(lli i=0;i<y.length();i++){
			if(y[i]=='&'){
				num0=(num0*9)%modval;
				den0=(den0*16)%modval;
				num1=(num1*1)%modval;
				den1=(den1*16)%modval;
				numa=(numa*3)%modval;
				dena=(dena*16)%modval;
				numA=(numA*3)%modval;
				denA=(denA*16)%modval;
			}
			else if(y[i]=='|'){
				num0=(num0*1)%modval;
				den0=(den0*16)%modval;
				num1=(num1*9)%modval;
				den1=(den1*16)%modval;
				numa=(numa*3)%modval;
				dena=(dena*16)%modval;
				numA=(numA*3)%modval;
				denA=(denA*16)%modval;
			}
			else if(y[i]=='^'){
				num0=(num0*4)%modval;
				den0=(den0*16)%modval;
				num1=(num1*4)%modval;
				den1=(den1*16)%modval;
				numa=(numa*4)%modval;
				dena=(dena*16)%modval;
				numA=(numA*4)%modval;
				denA=(denA*16)%modval;
			}
		}

		// cout<<num0<<" "<<num1<<" ";
		// cout<<numa<<" "<<numA<<"\n";
		lli gcdden=gcd(den0,modval);
		den0/=gcdden;
		den1/=gcdden;
		dena/=gcdden;
		denA/=gcdden;
		cout<<(num0*modInverse(den0,modval))%modval<<" "<<(num1*modInverse(den1,modval))%modval<<" ";
		cout<<(numa*modInverse(dena,modval))%modval<<" "<<(numA*modInverse(denA,modval))%modval<<"\n";

	}
}	