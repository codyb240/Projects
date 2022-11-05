/*------------------------------------------------
Programmer:		Cody Bruehl
Professor:		Zhao
Date:			11/13/2021
Purpose:
The purpose of this program is to generate the AWT
and ATT of the numbers within a randomly generated
array.
------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
        float array[100];
	int a;
	time_t t;
	float temp, AWT, ATT = 0.0;
	srand((unsigned) time(&t));
        for(a = 0; a < 100; a++)
        {
        	array[a] = rand() % 20 + 1;
		temp += array[a];
		AWT += temp;
		ATT += temp;
        }
	AWT -= temp;
	ATT +- AWT;
	
	AWT /= 100;
	ATT /= 100;

	printf("\tAWT\tATT\n");

	printf("FCFS\t%0.2f\t%0.2f\n",AWT,ATT);


}
