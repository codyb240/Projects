#include <iostream>
#include <cstdlib>

using namespace std;

class SimplePoint{

	private:
		int Integer1;
		int Integer2;
		
	public:
        SimplePoint()
        {
        	Integer1 = 10 + rand()%51;
            Integer2 = 10 + rand()%51;
		}
		SimplePoint(int x, int y){
			Integer1=x;
			Integer2=y;
			
		}
		
	void print(){
		cout << Integer1 << "\t" << Integer2 << endl;
	}
	
	void min();
				
};

void SimplePoint::min(){
	   
    if(Integer1 < Integer2)
    {
      cout<< Integer1<<endl;
    }
    else
    {
      cout<< Integer2<<endl;
    }    

}

	void max(SimplePoint obj){
	   
    /*if(Integer1 > Integer2)
    {
      return Integer1;
    }
    else
    {
      return Integer2;
    }    
    return max;*/
}

int main(){
	SimplePoint obj1;
	obj1.print();
	obj1.min();
	max(obj1);
	SimplePoint obj2(10,50);
	obj2.print();
	obj2.min();
	max(obj2);
	return 0;
}
		
		

