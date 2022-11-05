#include <iostream>
#include <cstdlib>

using namespace std;

int table[24];
void fillArray(int arr[], int size)
	{
		for (int i=0; i<size; i++)
		
		arr[i]=200+rand()%(450);
	}
	
void printArray(int arr[], int size)
	{
		for (int k=0; k<size; k++)
			{
			cout<<arr[k]<<"\t";
			if (k%6==5) cout<<"\n";
			}
	}


void partialSum(int array[], int size)
{
	int sum= 0; 
	for(int i = 0; i < size; i++)
  {
	sum= sum + array[i];
	
  }
	cout<<endl;
}

int main(){
	fillArray(table, 24);
	printArray(table, 24);
	partialSum(table, 24);
	printArray(table, 24);
	return 0;
}
