#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<vector>
#include<utility>
#include<conio.h>

using namespace std;

const int NUMNAMES = 1000; // Number of names in the file

const int BOYS = 0; //search all boy names

const int GIRLS = 1; //search all girl names

/***************FUNCTION PROTOTYPES ********************************/

void instructions(); // greet user, explain program

string getFileName(); // get the user's input for filename

string getPersonName(); // input from user - name to check in file

ifstream openTheFile(string fileName);

int findName(string name, string fileName, int gOrb);

void showResults(string who, string where, int girl, int boy, int choice);

void getChoice(int &choice);

void printTop20(string filename);

void printNamesStartingWithCharacter(string fileName,char c);

/********************************************************************/

int main()

{
  
  int choice=1;
  while(choice){

      instructions();

      getChoice(choice);
      
      if(!choice)
        break;
      // INPUT

      string fileName = getFileName();

      if(choice==4)
      {
        printTop20(fileName);
        continue;
      }

      string searchName = getPersonName(); // Input name to search for

      //PROCESS

      if(choice==5)
      {
        printNamesStartingWithCharacter(fileName,searchName[0]);
        continue;
      }

      int girlRank = findName(searchName, fileName, GIRLS);

      int boyRank = findName(searchName, fileName, BOYS);

      // OUTPUT

      showResults(searchName, fileName, girlRank, boyRank, choice);

      cout << "\n Type any key when finished viewing the output...\n ";

      getch();
  
  }
  
  return 0;

}

void getChoice(int &choice)

{

  cout << "Press one of the following keys to continue..\n"

    <<
    " 1 for searching boy's name \n"

    <<
    " 2 for searching girl's name \n"

    <<
    " 3 for searching both boy's and girl's name \n"

    <<
    " 4 for getting top 20 ranked boys and girls name \n"

    <<
    "0 for exit \n";
    cin>>choice;

}

void instructions()

{

  cout << "\n\nThis program will check the name you enter against the list of the "

    <<
    " most popular baby names in the file you ask for "

    <<
    "\n it will compare the name to both boys and girls popular names \n";

}

string getFileName()

{

  string fileName(""); //declare string object -- set to empty string

  cout << " First, enter the name of the file to search --> ";

  cin >> fileName; // get the input file name from the user

  return fileName;

}

string getPersonName()

{

  string theName;

  cout << "\n What name would you like us to search for? "

    <<
    "\n Be sure to capitalize only the first letter --> ";

  cin >> theName;

  return theName;

}

/* Open the file either opens the file and returns the ifstream object

associated with the physical fileName OR exits the program if the

file is not useable or not found

*/

ifstream openTheFile(string fileName)

{

  ofstream babyNames;

  babyNames.open(fileName);

  if (babyNames.fail())

  {

    cout << " Problems finding/opening file " << fileName

      <<
      "\n Please check the file name and try again."

      <<
      "\n This program will close now ...\n";

    exit(1);

  }

  return babyNames;

}

/*

showResults displays the results for search name in terms of boy/girl rank

*/

void showResults(string who, string where, int girlNum, int boyNum,int choice)

{

  // Results for girl's names and boy's names ranking

  cout << " in file " << where << ", " << who;

  if (girlNum == 0 && (choice==2 || choice==3))

    cout << " is not ranked among the top 1000 names for girls\n";

  else if((choice==2 || choice==3))

    cout << " is ranked number " << girlNum << " for girl names\n";

  if (boyNum == 0 && (choice==1 || choice==3))

    cout << ", is not ranked among the top 1000 names for boys\n";

  else if ((choice==1 || choice==3))

    cout << ", is ranked number " << boyNum << " for boy names\n";

}

/*

findName() uses the inpus for search name and the file to open the file

find the name (rank for boy OR girl name)

closes the file

returns the "rank"

*/

int findName(string name, string fileName, int boyOrGirl)

{

  ifstream inFile = openTheFile(fileName);

  bool found = false; // Stop searching flag - initially false

  int rank = 0; // value returned identifying name ranking

  int rNum; // ranking number read from the file per name

  string boyName, // read one by one from the input file

  girlName; // read one by one from the input file

  for (int i = 0; i < NUMNAMES && !found; i++) // search until found or no more names

  {

    inFile >> rNum; // format is rankNumber boyName girlName

    inFile >> boyName;

    inFile >> girlName;

    if (boyOrGirl == BOYS) // searching the boys names

    {

      if (name == boyName)

      {

        found = true; // flag to stop looking!

        rank = rNum; // set the return rank to the name number rank

      }

    } else // searching the girls names

      if (name == girlName)

    {

      found = true; // we can stop looking!

      rank = rNum; // set the return rank to the name number rank

    }

  } // finished the search loop

  inFile.close(); // we are finished -- close the file!

  return rank;

}

bool compareRanks(pair<int,pair<string,string>> a, pair<int,pair<string,string>> b) {
    return a.first<b.first;
}

void printTop20(string fileName){

  ifstream inFile = openTheFile(fileName);

  int rNum; // ranking number read from the file per name

  string boyName, // read one by one from the input file

  girlName; // read one by one from the input file
  
  vector<pair<int,pair<string,string>>> list(NUMNAMES);

  for (int i = 0; i < NUMNAMES ; i++) // search until found or no more names

  {

    inFile >> rNum; // format is rankNumber boyName girlName

    inFile >> boyName;

    inFile >> girlName;

    list[i]={rNum,{boyName,girlName}};

  } // finished the search loop

  sort(list.begin(),list.end(),compareRanks);
  
  cout<<"Rank \t Boy's Name \t Girl's Name\n";

  for(int i=0; i < 20 ;i++){

    cout<<setw(5)<<list[i].first<<"\t"<<

    setw(11)<<list[i].second.first<<"\t"<<

    setw(11)<<list[i].second.second<<"\n";

  }

  inFile.close();
}

void printNamesStartingWithCharacter(string fileName,char c){
    ifstream inFile = openTheFile(fileName);

  int rNum; // ranking number read from the file per name

  string boyName, // read one by one from the input file

  girlName; // read one by one from the input file
  
  vector<string> nameListBoy,nameListGirl;

  for (int i = 0; i < NUMNAMES ; i++) // search until found or no more names

  {

    inFile >> rNum; // format is rankNumber boyName girlName

    inFile >> boyName;

    inFile >> girlName;

    if(boyName[0]==c)
        nameListBoy.push_back(boyName);
    if(girlName[0]==c)
        nameListGirl.push_back(girlName);

  } 

  cout<<"Top Boys name starting with character "<<c<<"\n";
  for(int i=0;i<nameListBoy.size();i++){
    cout<<nameListBoy[i]<<"\n";
  }


  cout<<"Top Girls name starting with character "<<c<<"\n";
  for(int i=0;i<nameListGirl.size();i++){
    cout<<nameListGirl[i]<<"\n";
  }
  
  
}