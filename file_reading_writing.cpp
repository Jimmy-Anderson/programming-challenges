#include<iostream>
#include<fstream>
#include<string>

using namespace std;
 
int main()
{
	fstream outfile;
	string filename;
	cout<<"Enter file name:\n";
	cin>>filename;
	filename+=".txt";
	outfile.open(filename.c_str(),ios::out);
	if(!outfile)
	{
		cout<<"Error in creating file!!\n";
		return 0;
	}
	cout<<"File created Successfully!!\n";
	cout<<"Enter your name:\n";
	string s;
	cin.ignore();
	getline(cin,s);
	if(outfile.is_open())
	{
		outfile<<s;
		outfile.close();
	}
	else
		cout<<"Unable to open file\n";
	return 0;
}