#include<iostream>
using namespace std;

bool helper (int array[], int index, int size, int sum1, int sum2)
{
	if(index >= size)
	{
		return sum1 == sum2;	
	}	
	if(helper(array,index+1,size,sum1+array[index],sum2))
	{		
		return true;
	}	
	if(helper(array,index+1,size,sum1,sum2+array[index]))
	{		
		return true;
	}	
	return false;
}
bool splitArray(int array[],int size)
{
	return helper(array,0,size,0,0);
}

int main()
{
	int array[2] = {2,2};
	cout << splitArray(array,2) << endl;	
	int array1[2] = {2,3};
	cout << splitArray(array1,2) << endl;	
	int array2[3] = {5,2,3};
	cout << splitArray(array2,3) << endl;

return 0;	
}
