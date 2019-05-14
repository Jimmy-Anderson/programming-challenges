#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

// A utility function to multiply two matrices 
// a[][] and b[][].  Multiplication result is 
// stored back in b[][] 
void multiply(int a[4][4], int b[4][4]) 
{ 
    // Creating an auxiliary matrix to store elements  
    // of the multiplication matrix 
    int mul[4][4]; 
    for (int i = 0; i < 4; i++) 
    { 
        for (int j = 0; j < 4; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 0; k < 4; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
  
    // storing the muliplication resul in a[][] 
    for (int i=0; i<4; i++) 
        for (int j=0; j<4; j++) 
            a[i][j] = mul[i][j];  // Updating our matrix 
} 
  
// Function to compute F raise to power n-4. 
int power(int F[4][4], int n) 
{ 
    int M[4][4] = {{1,1}, {1,0}}; 
  
    // Multiply it with initial values i.e with 
    // F(0) = 0, F(1) = 1, F(2) = 1 
    if (n==1) 
    return 3*F[0][0] - 3*F[0][1]+ 1*F[0][1] ; 
  
    power(F, n/2); 
  
    multiply(F, F); 
  
    if (n%2 != 0) 
        multiply(F, M); 
  
    // Multiply it with initial values i.e with 
    // F(0) = 0, F(1) = 1, F(2) = 1 
    return 3*F[0][0] - 3*F[0][1]+ 1*F[0][1] ; 
} 
  
// Return n'th term of a series defined using below 
// recurrence relation. 
// f(n) is defined as 
//    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3 
// Base Cases : 
//    f(0) = 0, f(1) = 1, f(2) = 1 
int findNthTerm(int n) 
{ 
    int f[4][4]={{3,-3,1,0},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
  
    return power(F, n-4); 
} 
  
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        int f[4][4]={{3,-3,1,0},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
        cout<<findNthTerm(n)<<"\n";
        
    }
}