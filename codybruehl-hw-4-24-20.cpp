#include <iostream>
#include <cstdlib>
using namespace std;
class Node{
	private:
		int element;
		Node* next;
	public:
		Node(int x, Node* p){
			element=x;
			next=p;
		}
		Node(int x){
			element=x;
			next=NULL;
		}
		Node(){
			element=0;
			next=NULL;
		}
		int getElement(){return element;}
		void setElement(int x){element=x;}
		Node* getNext(){return next;}
		void setNext(Node* x){next=x;}
};

class List{
	private:
		Node* front;
		int size;
	public:
		Node* getFront(){return front;}
		void setFront(Node* x){front=x;}
		int getSize(){return size;}
		void setSize(int x){size=x;}
		List(){
			size=0;
			front=NULL;
		}
		void addFront(int x){
			Node * temp=new Node(x,front);
			front=temp;
			size++;
		}
		void addLast(int x){
			Node* temp=new Node(x);
			if (front==NULL){
				front=temp;
			}else{
				Node* temp1=front;
				for (int i=0; i<size-1;i++){
					temp1=(*temp1).getNext();
				}
				(*temp1).setNext(temp);
			}
			size++;
		}
		void addAfter(int x, Node* p){
			if (p==NULL){
				addFront(x);
			}else{
				Node* temp; //step1
				temp=new Node;//step2 and step3
				(*temp).setNext((*p).getNext());//step4
				(*temp).setElement(x);//step4.1
				(*p).setNext(temp);//step5
				size++;
			}
		}
		void remove(int x){
			Node* temp=front;
			if ((*temp).getElement()==x){
				front=(*front).getNext();
			}else{
				for (int i=0; i<size; i++){
					if ((*((*temp).getNext())).getElement()==x){
						break;
					}else{
						temp=(*temp).getNext();
					}
				}
				Node* temp2=(*temp).getNext();
				Node* temp3=(*temp2).getNext();
				(*temp).setNext(temp3);
				delete temp2;
				//(*temp).setNext((*((*temp).getNext())).getNext());
			}
			size--;
		}
		void removeFront(){
			if (size>0){
				Node* temp=front;
				front=front->getNext();//(*front).getNext();
				size--;
				delete temp;
			}	
		}
		void removeLast(){
			if (size==1){
				Node* temp=front;
				front=NULL;
				size--;
				delete temp;
			}
			if (size>1){
				Node* temp=front;
				for (int i=0; i<size-2 ;i++){
					temp=temp->getNext();
				}
				Node* temp1=temp->getNext();
				temp->setNext(NULL);
				size--;
				delete temp1;
			}
		}
		void print(){
			cout<<"********************************\n";
			//allocate memory for a pointer to a node called temp
			Node* temp;
			//store in temp the address of the first node in our list
			temp=front;
			//write a loop to visit the nodes in our list
			for (int i=0; i<size; i++){
				//display the element in the node to which temp point
				cout<<(*temp).getElement()<<endl;
				//make temp point to the next node
				temp=(*temp).getNext();
				
			}
			cout<<"********************************\n";
		}
		friend ostream& operator <<(ostream &os, const List &obj){
			os<<"********************************\n";
			Node* temp;
			temp=obj.front;
			for (int i=0; i<obj.size; i++){
				os<<(*temp).getElement()<<endl;
				temp=(*temp).getNext();
			}
			os<<"********************************\n";
			return os;
		}
			
};

class MultiList{
	private:
		List** hook;
		int size;
		int nbOfLists;	
	public:
		int getSize(){return size;}
		void setSize(int x){size=x;}
		int getNbOfLists(){return nbOfLists;}
		void setNbOfLists(int x){nbOfLists=x;}
		List** getHook() {return hook;}
		void setHook(List** p){hook=p;}
		MultiList(int x=2){
			size=0;
			nbOfLists=x;
			hook=new List*[nbOfLists];
			for (int i=0; i<nbOfLists; i++){
				hook[i]=new List;
			}
		}
		void addElement(int x){
			int range=500/nbOfLists;
			//cout<<"Value: "<<x
			hook[x/range]->addLast(x);
			//(*hook[x/(500/nbOfLists)]).addLast(x);
			size++;
		}
		void removeElement(int x){
			int range=500/nbOfLists;
			//cout<<"Value: "<<x
			hook[x/range]->remove(x);
			//(*hook[x/(500/nbOfLists)]).remove(x);
			size--;
		}
		void removeAllLasts(){
			for (int i=0; i<nbOfLists; i++){
				if ((*hook[i]).getSize()>0){
					(*hook[i]).removeLast();
					size--;
				}
			}
		}
		void print(){
			for (int i=0; i<nbOfLists; i++){
				cout<<"Element in list "<<i+1<<endl;
				(*hook[i]).print();
			}
		}
		//Copy constructor
		MultiList(const MultiList &obj){
			size=0;
			nbOfLists=obj.nbOfLists;
			hook=new List*[nbOfLists];
			for (int i=0; i<nbOfLists; i++){
				hook[i]=new List;
				Node *temp=obj.hook[i]->getFront();
				while(temp!=NULL){
					int elem=temp->getElement();
				hook[i]->addLast(elem);
					temp=temp->getNext();
			}
		}
}
		
		//overloaded operator <<
		friend ostream& operator <<(ostream &os, const MultiList &obj){
			   for (int i=0; i<obj.nbOfLists; i++){
				os<<"Element in list "<<i+1<<endl;
				os<<(*obj.hook[i]);
			} 
			return os;                               
		}		                      
};



int main(){
	MultiList obj1(5);
	for (int i=0; i<20; i++){
		obj1.addElement(rand()%501);
	}
	obj1.print();
	cout<<obj1;
	MultiList obj2(obj1);
	cout<<obj2;
	cout<<"enter an element to be removed.\n"; 
	cout<<"Choose an element from the elements displayed:\n";
	int rem;
	cin>>rem;
	obj1.removeElement(rem);
	cout<<obj1;
	cout<<obj2;
	return 0;
}
