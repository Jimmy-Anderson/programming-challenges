#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<vector>
#include<utility>
#include<conio.h>

using namespace std;

int gcd(int a,int b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
void readValues(int &a,int &b){
  cout<<"\nEnter first integer:     ";
  cin>>a;
  cout<<"Enter the second integer:";
  cin>>b;
}
void outputToFile(ofstream &File,int gcdValue){
  File<<gcdValue<<endl;
}
int main(){
  ofstream File;
  File.open("results.txt",ios::out|ios::trunc);
  for(int i=1;i<=4;i++){
    int a,b;
    readValues(a,b);
    int gcdValue=gcd(a,b);
    outputToFile(File,gcdValue);
  }
  File.close();

}