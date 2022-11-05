#include <iostream>

using namespace std;
	
class Student
{

	private:
		int ID;
		string name, email, major, phone; 
		static string UnivAddress;
		
	public:
		
		Student(){}
			Student(int x, string n, string em, string m, string p){
				ID=x;
				name=n;
				email=em;
				major=m;
				phone=p;
			}
		string getName(){return name;}
		void setName(string x){name=x;}
		
		string getEmail(){return email;}
		void setEmail(string x){email=x;}
		
		string getMajor(){return major;}
		void setMajor(string x){major=x;}
		
		string getPhone(){return phone;}
		void setPhone(string x){phone=x;}
		
		static string getUnivAddress(){return UnivAddress;}
		void setUnivAddress(string x){UnivAddress=x;}
		
		int getID(){return ID;}
		void setID(int x){ID=x;}
		
		void print(){
			cout << "*************************\n";
			cout << "Name:\t" << name << endl;
			cout << "Email:\t" << email << endl;
			cout << "Major:\t" << major << endl;
			cout << "Phone:\t" << phone << endl;
			cout << "ID:\t" << ID << endl;
		
		}
};

string Student::UnivAddress= "2800 W Gore Blvd";

int main(){
	
	cout<<"University:\t\t"<<Student::getUnivAddress()<<endl;
	Student Cody;
	Cody.print();
	Cody.setEmail("cb932509@cameron.edu");
	Cody.setID(932509);
	Cody.setMajor("CS");
	Cody.setName("Cody");
	Cody.setPhone("5807365979");
	Cody.print();
	Student John(111222, "John", "jd111222@cameron.edu", "IT", "5801112222");
	John.print();

return 0;
}
