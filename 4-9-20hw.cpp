#include<iostream>
#include<fstream>
#include <string>

using namespace std;


int main()
{

ofstream outFile;
outFile.open("Story.txt");

outFile << "The little green men had\n";
outFile << "pointed heads and orange\n";
outFile << "toes with one long curly\n";
outFile << "hair on each toe." << endl;

outFile.close();
ifstream inFile;
inFile.open("Story.txt");

string str1;
string str2;
string str3;
string str4;

getline(inFile,str1);
getline(inFile,str2);
getline(inFile,str3);
getline(inFile,str4);
outFile.open("DuplicateStory.txt");
for(int i=0; i<3; i++)outFile << str1 <<endl;
for(int i=0; i<3;i++)outFile << str2 <<endl;
for(int i = 0; i<3;i++)outFile << str3 <<endl;
for(int i = 0; i<3;i++)outFile << str4 <<endl;


outFile.close();

return 0;
}
