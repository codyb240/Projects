/*----------------------------------------------------------------\
Programmer: Cody Bruehl
Program:	1
Date:		9/19/21
Course:		Algorithm Analysis
Description:
			This program creates the attendance report for a course
			using the original roster and the attendance list for 
			two sessions.
\----------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int maxSize = 20;
	int counter = 0;
	string roster[maxSize]={"Burton", "Cossio", "Coxers", "Dykins", "Fitch", "Hudson", "Lamsal", "Pierce", "Punzer", "Snyder"};
	string day1[maxSize]={"Fitch", "Snyder", "Burton", "Pierce", "Dykins", "Proctor", "Coxers", "Cossio"};
	string day2[maxSize]={"Lamsal", "Coxers", "Fitch", "Cossio", "Snyder", "Burton", "Proctor", "Dykins", "Delacruz"};
	
    
    for(int i = 0; i < maxSize; i++)
	{
    	int x;
        for(x = 0; x < maxSize; x++)
            if (day1[i] == roster[x])
                break;
 
        if (x == maxSize)
            roster[i+1] = day1[i];
            for(int i = 0; i < maxSize; i++)
    	{
    	int x;
        for( x = 0; x < maxSize; x++)
            if (day2[i] == roster[x])
                break;
 
        if (x == maxSize)
            roster[i+1] = day2[i];
    	}
	}
	
	cout << "Attendance\tName" << endl;
	cout << "--------------------------------" << endl;
	for(int i=0; i < maxSize-1; i++){
		if(roster[i] == "")
			break;

		for(int x=0; x < maxSize-1; x++){
			if(day1[x] == roster[i])
				counter++;
			
			if(day2[x] == roster[i])
				counter++;
			
		}
		cout << counter << "           \t" << roster[i] << endl;
		counter = 0;
	}

	return 0;
}
