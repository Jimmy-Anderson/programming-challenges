#include<bits/stdc++.h>
using namespace std;
long long count(long long x, long long Y[], long long n, long long NoOfY[]) 
{ 
    // If x is 0, then there cannot be any value in Y such that 
    // x^Y[i] > Y[i]^x 
    if (x == 0) return 0; 
  
    // If x is 1, then the number of pais is equal to number of 
    // zeroes in Y[] 
    if (x == 1) return NoOfY[0]; 
  
    // Find number of elements in Y[] with values greater than x 
    // upper_bound() gets address of first greater element in Y[0..n-1] 
    long long* idx = upper_bound(Y, Y + n, x); 
    long long ans = (Y + n) - idx; 
  
    // If we have reached here, then x must be greater than 1, 
    // increase number of pairs for y=0 and y=1 
    ans += (NoOfY[0] + NoOfY[1]); 
  
    // Decrease number of pairs for x=2 and (y=4 or y=3) 
    if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]); 
  
    // Increase number of pairs for x=3 and y=2 
    if (x == 3)  ans += NoOfY[2]; 
  
    return ans; 
} 
  
// Function to return count of pairs (x, y) such that 
// x belongs to X[], y belongs to Y[] and x^y > y^x 
long long countPairs(long long X[], long long Y[], long long m, long long n) 
{ 
    // To store counts of 0, 1, 2, 3 and 4 in array Y 
    long long NoOfY[5] = {0}; 
    for (long long i = 0; i < n; i++) 
        if (Y[i] < 5) 
            NoOfY[Y[i]]++; 
  
    // Sort Y[] so that we can do binary search in it 
    sort(Y, Y + n); 
  
    long long total_pairs = 0; // Initialize result 
  
    // Take every element of X and count pairs with it 
    for (long long i=0; i<m; i++) 
        total_pairs += count(X[i], Y, n, NoOfY); 
  
    return total_pairs; 
} 
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long n,m;
	    cin>>n>>m;
	    long long a[n];
	    for(long long i=0;i<n;i++)
	        cin>>a[i];
	    long long b[m];
	    for(long long i=0;i<m;i++)
	        cin>>b[i];
	    cout<<countPairs(a,b,n,m)<<"\n";
	}
}