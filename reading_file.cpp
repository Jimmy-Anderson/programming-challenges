#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	fstream file;
	cout<<"Input the file name you want to open\n";
	string filename,line;
	cin>>filename;
	file.open(filename.c_str(),ios::in|ios::out);
	if(file.is_open())
	{
		while(getline(file,line))
			cout<<line<<"\n";
		file.close();
	}
	else
		cout<<"Unable to open the file\n";
	return 0;
}
