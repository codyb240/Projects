#include <iostream>
#include <cstdlib>
using namespace std;

class DynamicArray{
	private:
		int* storage;
		int capacity;
		int nbOfElements;
	public:
		DynamicArray(int c=10){
			capacity=c;
			nbOfElements=0;
			storage=new int[capacity];
		}
		void print(){
			cout<<"****************************\n";
			cout<<"Capacity: \t\t"<<capacity<<endl;
			cout<<"Nb of elements: \t"<<nbOfElements<<endl;
			for (int i=0; i<nbOfElements; i++){
				cout<<*(storage+i)<<"\t"; //cout<<storage[i]<<"\t";
				if (i%4==3) cout<<endl;
			}
			cout<<endl;
			cout<<"****************************\n";
		}
		void addElement(int x){
			//if storage full
			if (nbOfElements==capacity){
			
				//1-allocate memory for a new pointer to int newStorage
				int* newStorage;
				//2-double the capacity
				capacity=2*capacity;
				//3-allocate dynamic memory for an array with a size equal
				//to the capacity and store its address in newStorage
				newStorage=new int[capacity];
				//4-move elements from old storage to new storage
				for (int i=0; i<nbOfElements; i++){
					newStorage[i]= storage[i];
					//*(newStorage+i)=*(storage+i);
				}
				//5-delete old storage
				delete [] storage;
				//6- store the address of new storage in storage
				storage=newStorage;
			}
			//store x in array at index nbOfElements
			storage[nbOfElements]=x;
			//increase nbOfElements by 1
			nbOfElements++;	
		}
		void removeElement(int x);
		//Copy constructor
			
				DynamicArray( DynamicArray &obj1, DynamicArray &obj2, DynamicArray &obj3){
					storage = new int[capacity]	;
					*storage = *obj1.storage;
					
					storage = new int[capacity]	;
					*storage = *obj2.storage;
					
					storage = new int[capacity]	;
					*storage = *obj3.storage;
		}
			
		//overloaded + operator
		DynamicArray operator+(DynamicArray& n){
			int min = capacity; // the size of smaller array
    int max = capacity; // the size of a large array
    if (min > n.capacity) min = n.capacity;
    if (max < n.capacity) max = n.capacity;

    DynamicArray objA;
    objA.capacity = max;
    objA.storage = new int[objA.capacity]; // allocate memory
    // ---

    // element summation loop
    for (int i = 0; i < max; i++)
    {
      if (i < min)
        objA.storage[i] = storage[i] + objA.storage[i];
      else
      {
        if (capacity < max)
          objA.storage[i] = objA.storage[i];
        else
          objA.storage[i] = storage[i];
      }
    }
  return objA;
		}
		
};

void DynamicArray::removeElement(int x){
	//traverse the array until you reach the element to be removed
	for (int i=0; i<nbOfElements; i++){
		if (x==storage[i]){//if (x==*(storage+i))
			//move all elements after it one position to the left
			for (int k=i; k<nbOfElements-1; k++){
				storage[k]=storage[k+1];
			}
			break;
		}
	}
	//decrease nbOfElements by one
	nbOfElements--;
	if (nbOfElements<=capacity/2){
		int* temp= new int[capacity/2];
		capacity/=2;
		for (int i=0; i<nbOfElements; i++){
			temp[i]=storage[i];
		}
		delete [] storage;
		storage=temp;
	}
}

int main(){
	DynamicArray obj1;
	for (int i=0; i<12; i++){
		obj1.addElement(rand()%50);
	}
	obj1.print();
	DynamicArray obj2(obj1);
	obj2.print();
	DynamicArray obj3=obj1+obj2;
	obj3.print();
	for (int i=0; i<4; i++){
		obj1.addElement(rand()%50);
	}
	obj1.print();
	DynamicArray obj4=obj1+obj2;
	obj4.print();
	
	return 0;
		
}
