#include<bits/stdc++.h>
using namespace std;


void generateLookup(int a,int b,int lookup[]){
    for(int i=0;i<26;i++){
        int codenumber=a+b*i;
        lookup[i]=codenumber%26;//Wrappping around so codenumber lies in [0,26)
    }
}
string encode(string s,int lookup[]){
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]>=65&&s[i]<=90){
            res.push_back(lookup[s[i]-'A']+'A');
        }
        else if(s[i]>=97&&s[i]<=122){
            res.push_back(lookup[s[i]-'a']+'a');
        }
        else{
            res.push_back(s[i]);
        }
    }
    return res;
}
int findKeyInLookup(int value,int lookup[]){
    for(int i=0;i<26;i++){
        if(lookup[i]==value)
            return i;
    }
    return 0;
}
string decode(string s,int lookup[]){
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]>=65&&s[i]<=90){
            res.push_back(findKeyInLookup(s[i]-'A',lookup)+'A');
        }
        else if(s[i]>=97&&s[i]<=122){
            res.push_back(findKeyInLookup(s[i]-'a',lookup)+'a');
        }
        else{
            res.push_back(s[i]);
        }
    }
    return res;
}
void printlookup(int lookup[]){
    cout<<"Lookup Values are\n";
    for(int i=0;i<26;i++){
         cout<<i+'a'<<" "<<i<<" "<<lookup[i]<<"\n";
    }
}
int main()
{
    int choice=1;
    while(choice){
        cout<<"Enter your choice of operation\n";
        cout<<"1 for Encode Message to encode.txt\n";
        cout<<"2 for Decode encoded message to decode.txt\n";
        cout<<"0 for exit\n";
        cin>>choice;
        if(!choice) break;
        if(choice==1){
            cout<<"Enter the name of the message file\n";
            string fileName;
            cin>>fileName;
            ifstream myfile;
            myfile.open(fileName);
            if (myfile.is_open())
            {
                int i,l=0;
                char ch;
                while(myfile.get(ch)){
                    i=ch;
                    if((i > 63 && i < 91) || (i > 96 && i < 123))
                            l++;
                }
                myfile.close();
                int a=l%25+1;
                int b=(l%6)*2+1;
                int lookup[26];
                generateLookup(a,b,lookup);
                // printlookup(lookup);
                ofstream outputFile;
                string line;
                myfile.open(fileName);
                outputFile.open("encode.txt");
                if(myfile.is_open()){
                    while ( getline (myfile,line) )
                    {
                      string encodedLine = encode(line,lookup);
                      outputFile<<encodedLine<<endl;
                    }
                }
                else cout << "Unable to open file\n";
                outputFile.close();
                myfile.close();
                cout<<"Output generated in encode.txt file\n";
            }
            else cout << "Unable to open file";
        }
        if(choice==2){
            cout<<"Enter the name of the encoded message file\n";
            string fileName;
            cin>>fileName;
            ifstream myfile;
            myfile.open(fileName);
            if (myfile.is_open())
            {
                int l = 0,i;
                char ch;
                while(myfile.get(ch)){
                    i=ch;
                    if((i > 63 && i < 91) || (i > 96 && i < 123))
                            l++;
                }
                myfile.close();
                int a=l%25+1;
                int b=(l%6)*2+1;
                int lookup[26];
                generateLookup(a,b,lookup);
                // printlookup(lookup);
                ofstream outputFile;
                string line;
                myfile.open(fileName);
                outputFile.open("decode.txt");
                if(myfile.is_open()){
                    while ( getline (myfile,line) )
                    {
                      string decodedLine = decode(line,lookup);
                      outputFile<<decodedLine<<endl;
                    }
                }
                else cout << "Unable to open file\n";
                outputFile.close();
                myfile.close();
                cout<<"Output generated in decode.txt file\n";
            }
            else cout << "Unable to open file";
        }

    }

}
