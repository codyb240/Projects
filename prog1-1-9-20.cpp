#include <iostream>
#include <cstdlib>
using namespace std;

int table[5][4];
void fill(int nbOfRows, int nbOfColumns){
	/*for (int i=0; i<nbOfColumns; i++){
		for (int j=0; j<nbOfRows; j++){
			table[j][i]=10 +rand()%991;
		}
	}*/
	for (int k=0;k<nbOfRows*nbOfColumns;k++){
		table[k/nbOfColumns][k%nbOfColumns]=10 +rand()%991;
	}
}
void print1(int nbOfRows, int nbOfColumns){
	for (int i=0; i<nbOfColumns; i++){
		for (int j=0; j<nbOfRows; j++){
			cout<<table[j][i]<<"\t";
		}
		cout<<endl;
	}
}

void print2(int nbOfRows, int nbOfColumns){
	for (int i=0; i<nbOfRows; i++){
		for (int j=0; j<nbOfColumns; j++){
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void sort(int nbOfRows, int nbOfColumns)
	{
		int temp
		int min = array[0];

	for(int k = size+1; k > 0; k++)
{
	  for(int i = 0; i < k; i++) 
{
	if(array[i] > array[i+1]) 
	swap(array[i], array[i+1]);
}
}

	
}
void sort(int nbOfRows, int nbOfColumns)
{
	int total=nbOfRows*nbOfColumns;
	for (int pos= 0; pos < total; pos++)
		int temp= table[pos/nbOfColumns][pos%nbOfColumns];
		int loc=pos;
		for (int k=pos; k<nbOfRows*nbOfColumns; k++)
		{
			if (temp>table[k/nbOfColumns][k%nbOfColumns])
			{
				temp>table[k/nbOfColumns][k%nbOfColumns]
				loc=k;
			}
		}
		int temp1=table[pos/nbOfColumns][pos%nbOfColumns];
		table[pos/nbOfColumns][pos%nbOfColumns]=temp;
		table[pos/nbOfColumns][pos%nbOfColumns]=temp1;
	}
		
}

int total(int nbOfRows, int nbOfColumns) // compute the sum of the elements of the array
{
	int total = 0;

	for(int c=0; c < nbOfColumns; c++)
	{
		for(int r=0; r < nbOfRows; r++)	
		{
			total= total + table[c][r];
 		}
	}

  return total;

}

int even(int nbOfRows, int nbOfColumns)
{
	int even = 0;
	
	for(int c=0; c < nbOfColumns; c++)
	{
		for(int r=0; r < nbOfRows; r++)
		{
			if(table[c][r] % 2 == 0)	
			{
				even= even + table[c][r];
  			}
  		}
  	}
  	return even;

}

int odd(int nbOfRows, int nbOfColumns)
{
	int odd = 0;
	
	for(int c=0; c < nbOfColumns; c++)
	{
		for(int r=0; r < nbOfRows; r++)
		{
			if(table[c][r] % 2 != 0)	
			{		
				odd= odd + table[c][r];
  			}
  		}
	}
  return odd;

}


int main(){
	fill(5,4);
	print1(5,4);
	cout<<"*****************************************\n";
	print2(5,4);
	sort(5,4);
	print2(5,4);
 cout << "the total is = "	<< total(5,4) << endl;
 cout << "The sum of the even numbers is = " << even(5,4) << endl;
  cout << "The sum of the odd numbers is = " << odd(5,4) << endl;
	return 0;
}
