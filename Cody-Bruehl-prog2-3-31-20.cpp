#include <iostream>
using namespace std;

class Person{
	//private:
	protected:
		string name;
		long int phone;
		string address;
	public:
		Person(string n=" ", long int p=1111, string ad="Lawton" ){
			name=n;
			phone=p;
			address=ad;
		}
		void setName(string x){
			name=x;
		}
		string getName(){
			return name;
		}
		void setPhone(long int x){
			phone=x;
		}
		long int getPhone(){
			return phone;
		}
		void setAddress(string x){
			address=x;
		}
		string getAddress(){
			return address;
		}
		void print(){
			cout<<"*******************\n";
			cout<<"Name:\t\t"<<name<<endl;
			cout<<"Phone:\t\t"<<phone<<endl;
			cout<<"Address:\t"<<address<<endl;
		}
};
class Student: public Person{
	private:
		int GPA;
		string major;
	public:
	//OPTION 1
		//if variable are protected in class Person
		Student(string n=" ", long int p=1111, string ad="Lawton", int gpa=3, string m="CS"){
			name=n;
			phone=p;
			address=ad;
			GPA=gpa;
			major=m;
		}
	//OPTION 2
		//if varaiable are private in class Person
		/*Student(string n=" ", long int p=1111, string ad="Lawton", int gpa=3, string m="CS"):
		Person(n,p,ad){
			GPA=gpa;
			major=m;
		}*/
	//OPTION 3
		//if varaiable are private in class Person
		/*Student(string n=" ", long int p=1111, string ad="Lawton", int gpa=3, string m="CS"){
			setName(n);
			setPhone(p);
			setAddress(ad);
			GPA=gpa;
			major=m;
		}
		void print(){
			Person::print();
			cout<<"GPA:\t\t"<<GPA<<endl;
			cout<<"Major:\t\t"<<major<<endl;
		}*/
};
//add a class instructor derived from class Person having two extra data members dept & office
//write a constructor and print function.
class Instructor: public Person{
	private: 
		string dept;
		string office;
	public:
		string getDept(){
			return dept;
		}
		void setDept(string s){
			dept=s;
		}
		string getOffice(){
			return office;
		}
		void setOffice(string s){
			office=s;
		}
		Instructor(string n=" ", long int p=1111, string ad="Lawton", string d="CS", string o="HH212"):
			Person(n,p,ad){
				dept=d;
				office=o;
			}
		void print(){
			cout<<"*******************\n";
			cout<<"Name:\t\t"<<getName()<<endl;
			cout<<"Phone:\t\t"<<getPhone()<<endl;
			cout<<"Address:\t"<<getAddress()<<endl;
			cout<<"Department:\t"<<dept<<endl;
			cout<<"Office:\t\t"<<office<<endl;
		}
};
class Tutor: public Student, Instructor{
	private:
		
	public:
		Tutor(string n=" ", long int p=1111, string ad="Lawton", int gpa=3, string m="CS",string d="CS", string o="HH212"):
			Student(n,p,ad,gpa,m){
				setDept(d);
				setOffice(o);
		}
		void print(){
			Student::print();
			cout<<"Department:\t"<<getDept()<<endl;
			cout<<"Office:\t\t"<<getOffice()<<endl;
		}
		

};

int main(){
	Person obj1("Smith", 2223333, "2800 W Gore Blvd Lawton, OK 73505");
	obj1.print();
	Student obj2("Trump",4445678, "Washington", 3.5, "PS");
	obj2.print();
	Instructor obj3("Johnny", 1112233, "Oklahoma", "Math", "B111");
	obj3.print();
	Tutor obj4("Dave", 2222222, "Texas", 3.4, "math", "C&T", "HH203");
	obj4.print();
	return 0;
}
