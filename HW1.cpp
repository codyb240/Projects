#include <iostream>

using namespace std;

class Tool{
	private:
		int strength;
		char type;
	public:
		void setStrength(int x){strength=x;}
		int getStrength(){return strength;}
		void setType(char x){type=x;}
		char getType(){return type;}
};

 

class Scissors: public Tool{
	private:

		
	public:
		Scissors(int x){
			setStrength(x);
			setType('s');
			}
		
		bool fight(Tool x){
			char temp1=x.getType();
			int temp2=x.getStrength();
			char temp3=getType();
			int temp4=getStrength();
			
			if(temp1=='r'){
				return temp4/2>temp2;
			}else if(temp1=='p'){
				return 2*temp4>temp2;
			}
		}
};

 

class Paper: public Tool{
	private:

		
	public:
		Paper(int x){
			setStrength(x);
			setType('p');
			}
			
			bool fight(Tool x){
			char temp1=x.getType();
			int temp2=x.getStrength();
			char temp3=getType();
			int temp4=getStrength();
			
			if(temp1=='s'){
				return temp4/2>temp2;
			}else if(temp1=='r'){
				return 2*temp4>temp2;
			}
		}
};

 

class Rock: public Tool{
	private:
	
		
	public:
		Rock(int x){
			setStrength(x);
			setType('r');
			}
			
			bool fight(Tool x){
			char temp1=x.getType();
			int temp2=x.getStrength();
			char temp3=getType();
			int temp4=getStrength();
			
			if(temp1=='p'){
				return temp4/2>temp2;
			}else if(temp1=='s'){
				return 2*temp4>temp2;
			}
		}
};

 

int main() {

                // Example main function

                // You may add your own testing code if you like

                Scissors s1(5);

                Paper p1(7);

                Rock r1(15);

                cout << s1.fight(p1) << p1.fight(s1) << endl;

                cout << p1.fight(r1) << r1.fight(p1) << endl;

                cout << r1.fight(s1) << s1.fight(r1) << endl;

 

                return 0;

}


