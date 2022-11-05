#include <iostream>

using namespace std;
class DNode{
	private:
		int element;
		DNode* next;
		DNode* prev;	
	public:
		DNode(int x=0, DNode* n=NULL,DNode* p=NULL){
			element=x;
			next=n;
			prev=p;
		}
		int getElement(){return element;}
		void setElement(int x){element=x;}
		DNode* getNext(){return next;}
		void setNext(DNode* n){next=n;}
		DNode* getPrev(){return prev;}
		void setPrev(DNode* n){prev=n;}
		
};
class CircularList{
	private:
		int size;
		DNode* front;
		DNode* rear;
	public:
		CircularList(){
			size=0;
			front=NULL;
			rear=NULL;
		}
		void addFront(int x){
			if (size==0){
				front=new DNode(x);
				rear=front;
				front->setNext(front);
				front->setPrev(front);
			}else{
				DNode* temp=new DNode(x,front, rear);
				front->setPrev(temp);
				rear->setNext(temp);
				front=temp;
			}
			size++;
		}
		void addrear(int x){
			if (size==0){
				front=new DNode(x);
				rear=front;
				front->setNext(front);
				front->setPrev(front);
			}else{
				DNode* temp=new DNode(x,front, rear);
				front->setPrev(temp);
				rear->setNext(temp);
				rear=temp;
			}
			size++;
		}
		void remove(int x){
			if (size>0){
				DNode* temp=front;
				for (int i=0; i<size; i++){
					if (temp->getElement()==x){
						break;
					}
					else{
						temp=temp->getNext();
					}
				}
				if (temp->getElement()==x){
					if (size==1){
						front=rear=NULL;
						delete temp;
					}else{
				DNode* temp2=(*temp).getNext();
				DNode* temp3=(*temp2).getNext();
				(*temp).setNext(temp3);
				delete temp2;
						
					}
					size--;
				}
			}
		}
		void removeFront(){
		if(size>0){
            DNode* temp=front;
            front=temp->getNext();
            delete temp;
        }
            else{
            front=rear=NULL;
    }
            size--;
        }
		void removeRear(){
			if(size>0){
            DNode* temp=rear;
            rear=temp->getPrev();
            delete temp;
        }
            else{
            rear=front=NULL;
    }
            size--;
        }
		void print(int rep=1){
			cout<<"************************\n";
			DNode* temp=front;
			for (int i=0; i<rep*size; i++){
				cout<<temp->getElement()<<endl;
				temp=temp->getNext();
			}
		}
		
		
		
		
		
};
int main(){
	CircularList obj1;
	for (int i=0; i<5; i++){
		obj1.addFront(20+i*100);
		obj1.addrear(50+i*1000);
	}
	obj1.print(1);
	obj1.removeFront();
	obj1.print(2);
	obj1.removeRear();
	obj1.print(1);
	obj1.remove(2050);
	obj1.print(1);
	return 0;
}
