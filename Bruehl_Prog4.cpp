/*-------------------------------------------------------------
Programmer:		Cody Bruehl
Program #:		4
Due Date:		12/5/21
Purpose:
This program shows common operations using
the Divide and Conquer method.
-------------------------------------------------------------*/
#include <iostream>
using namespace std;

int arrB[7];
int i;

void print(int arrA[], int left, int right){	//print elements of the array from left to right
	if(left == right){
		cout << arrA[left] << " ";
		return;
	}
	int mid = (left + right) / 2;
	print(arrA, left, mid);
	print(arrA, 1 + mid, right);
}

int total(int arrA[], int left, int right){		//Return the sum of elements in array from left to right
	if(left == right){
		return arrA[left];
	}
	int mid = (left + right) / 2;
	int count1 = total(arrA, left, mid);
	int count2 = total(arrA, 1 + mid, right);
	return count1 + count2;
}

int smallest(int arr[], int left, int right, int min){		//Return smallest element of array from left to right
	if(left == right){
		if(min > arr[left]){
			min = arr[left];
		}
		return min;
	}
	int mid = (left + right) / 2;
	min = smallest(arr, left, mid, min);
	min = smallest(arr, 1 + mid, right, min);
	return min;
}

int frequency(int arr[], int left, int right, int key){		//Return frequency count of key in array from left to right
	int mid = (left + right) / 2;							
	if((left > right) || (left == right && arr[left] != key)){
		return 0;
	}else if(left == right && arr[left] == key){
		return 1;
	}else
	return frequency(arr, left, mid, key) + frequency(arr, 1 + mid, right, key);
}

bool sorted(int arr[], int left, int right){	//Return true if elements from left to right are sorted.
	bool answer;								//Return false if elements from left to right are not sorted.
	if(left == right){
		return true;
	}else if(right - left == 1){
		if(arr[left] < arr[right]){
			return true;
		}else{
			return false;
		}
	}
	int mid = (left + right) / 2;
	answer = sorted(arr, left, mid);
	answer = sorted(arr, 1+mid, right);
	return answer;
}

void reverse(int arr[], int left, int right){	//Reverses the array's elements from left to right
	if(left == right){														
		arrB[i] = arr[left];
		i++;
		return;
	}
	int mid = (left + right) / 2;
	reverse(arr, 1+mid, right);
	reverse(arr, left, mid);
}

int main(){
	int arrA[] = {10, 20, 30, 40, 50, 60, 70};
	int left = 0;
	int right = 6;
	int key;
	int minny = 75;
	
	cout << "The array is: ";
	print(arrA, left, right);
	cout << endl;
	cout << "Total value of all array elements is: " << total(arrA, left, right) << endl;
	cout << "Smallest element in the array: " << smallest(arrA, left, right, minny) << endl;
	cout << "Enter a key to look for in the array: ";
	cin >> key;
	cout << "Your key is in the array " << frequency(arrA, left, right, key) << " time(s)!" << endl;
	if(sorted(arrA, left, right)){
		cout << "The array has been sorted" << endl;
	}else{
		cout << "The array has not been sorted" << endl;
	}
	cout << "Reverse reverse: "; //everybody clap your hands!! :D
	reverse(arrA, left, right);
	print(arrB, left, right);
	return 0;
}
