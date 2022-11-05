/*------------------------------------------------
Programmer:		Cody Bruehl
Professor:		Moinian
Date:			11/13/2021
Purpose:
This program uses the decrease-by-one-and-conquer 
technique to find the smallest number between a 
set of random numbers. It also is meant to give
the closest two numbers within a given set of 
numbers.
------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int smallest(int array[], int left, int right)
{
	if(left == right)
		return array[left];
		
		int mid = (left + right) / 2;
		int s1 = smallest(array, left, mid);
		int s2 = smallest(array, mid+1, right);
		return min(s1, s2);
	
}

void closestPair(int array[], int left, int right, int& index1, int& index2, int& minDist)
{
	int temp = right;
	int temp2;
	if(right == 1)
	{
		minDist = abs(array[left] - array[right]);
		index1 = left;
		index2 = right;
	}
	else
	{
		minDist = abs(array[left] - array[right]);
		index1 = left;
		index2 = right;
		right--;
		for(int i = right; i > 0; i--)
		{
			for(int j = left; j <= right; j++)
			{
				
				temp2 = abs(array[j] - array[i]);
				if(temp2 < minDist && i != j)
				{
				minDist = temp2;
				index1 = i;
				index2 = j;	
				}
			}
		}
	}	
}

void randnum(int array[], int N)
{
	srand (time(NULL));
	cout << "Array = ";
	for(int i = 0; i < N; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << " ";
	}
	cout << "\n\n";	
}

int main()
{
	const int N = 10;
	int array[N];
	
	int left = 0;
	int right = N - 1;
	
	int index1, index2, minDist;
	
	randnum(array, N);
	
	cout << "Smallest element = " << smallest(array, left, right) << "\n\n";
	
	closestPair(array, left, right, index1, index2, minDist);
	
	cout << "Closest pair = " << array[index1] << ", " << array[index2] << endl;
	cout << "Distance = " << minDist;
}
