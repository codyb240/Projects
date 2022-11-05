#include <iostream>
#include <cstdlib>
using namespace std;

int min(int array[], int size)
{
	int min = array[0]; 

	for(int i = 0; i < size; i++) 
  {
 	if(array[i] < min)

 	min = array[i];
  }
  return min;
}
//------------------------------------------------
int max(int array[], int size)
{
	int max = array[0]; 

	for(int i = 0; i < size; i++) 
  {
 	if(array[i] > max)
	
	max = array[i];
  }
  return max;
}
//------------------------------------------------
int average(int array[], int size)
{

	int sum=0;
	
	int average;
	
	for(int i = 0; i < size; i++)
  {
    average += array[i];
  }

    return (average / size );
}

//------------------------------------------------
int sum(int array[], int size)
{
	int sum= 0; 
	for(int i = 0; i < size; i++)
  {
	sum= sum + array[i];
  }
  return sum;
}
//------------------------------------------------
void fill(int arr[], int size){
	for (int i=0; i<size; i++){
		arr[i]=1+rand()%(100);
	}
}
//------------------------------------------------
void print(int arr[], int size){
	for (int k=0; k<size; k++){
		cout<<arr[k]<<"\t";
		if (k%5==4) cout<<"\n";
	}
}
//------------------------------------------------
int main(){
	int table[20];
	//cout<<sizeof(int)<<endl;
	fill(table, 20);
	print(table, 20);
	cout << "The smallest number = " << min(table, 20) << endl;
	cout << "The largest number = " << max(table, 20) << endl;
	cout << "Sum of the numbers = " << sum(table, 20) << endl;
	cout << "Average of the numbers = " << average(table, 20) << endl;
	return 0;
}
