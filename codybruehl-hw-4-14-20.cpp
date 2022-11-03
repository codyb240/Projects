#include<iostream>
#include<fstream>
#include <string>

using namespace std;

int main()
{
string fName;
string sName;
string city;

ofstream outFile;
outFile.open("Classmates.txt");

for (int i=0; i<3; i++){
cout << "Enter a class mates first name\t";
cin >> fName;
cout << "Enter the classmates surname\t";
cin >> sName;
cout << "What is their city?\t";
cin >> city;
outFile << fName << " " << sName << ", " << city << endl;
}

outFile.close();
ifstream inFile;
inFile.open("Classmates.txt");

string str1;
string str2;
string str3;

getline(inFile,str1);
getline(inFile,str2);
getline(inFile,str3);

cout<<str1<<endl;
cout<<str2<<endl;
cout<<str3<<endl;

outFile.close();
inFile.close();

return 0;
}
