#include<iostream>
#include<fstream>
#include <string>

using namespace std;


int main()
{

ofstream outFile;
//ifstream inFile;
string str1= "The little green men had";
string str2= "pointed heads and orange";
string str3= "toes with one long curly";
string str4= "hair on each toe.";
outFile.open("Story.txt");

outFile << "The little green men had\n";
outFile << "pointed heads and orange\n";
outFile << "toes with one long curly\n";
outFile << "hair on each toe." << endl;

outFile.close();

outFile.open("DuplicateStory.txt");

outFile <<str1<<endl;
outFile<<str1<<endl;
outFile<<str1<<endl;
outFile<<str2<<endl;
outFile<<str2<<endl;
outFile<<str2<<endl;
outFile<<str3<<endl;
outFile<<str3<<endl;
outFile<<str3<<endl;
outFile<<str4<<endl;
outFile<<str4<<endl;
outFile<<str4<<endl;

outFile.close();


/*while(getline(inFile, str1)){
		outFile << str1;
	}


while(getline(inFile, str2)){
		outFile << str2;
	}


while(getline(inFile, str3)){
		outFile << str3;
	}


while(getline(inFile, str4)){
		outFile << str4;
	}*/

return 0;
}
