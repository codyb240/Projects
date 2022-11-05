#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Point{
	
	private:
		float coord1;
		float coord2;
		static int nbOfPoints;
	public:
		Point(float x=0, float y=0){
			coord1=x;
			coord2=y;
			nbOfPoints++;
		}
		float getCoord1(){return coord1;}
		void setCoord1(float x){
			coord1=x;
		}
		float getCoord2(){return coord2;}
		void setCoord2(float x){
			coord2=x;
		}
		static int getNbOfPoints(){return nbOfPoints;}
		static void setNbOfPoints(int x){nbOfPoints=x;}
		
		void print(){
			cout << "("<<coord1<<", "<<coord2<<")\t\tNumber of Points: "<<nbOfPoints<<endl;
		}
		float distanceTo(Point p){
			return sqrt((p.coord1-coord1)*(p.coord1-coord1)+ pow((p.coord2-coord2),2));
		}
		float slope(Point p);
	
};

int Point::nbOfPoints=0;

	float Point::slope(Point p){
		return (p.coord2-coord2)/(p.coord1-coord1);
	}

int main(){
	Point P1;
	P1.print();
	Point P2(5);
	P2.print();
	Point P3(3,4);
	P3.print();
	Point P4(3,5);
	cout<<"The distance between P1 and P2 is: "<<P1.distanceTo(P2)<<endl;	
	cout<<"The slope between P1 and P3 is: "<<P1.slope(P3)<<endl;
	cout<<"The slope between P3 and P4 is: "<<P3.slope(P4)<<endl;
	cout<<Point::getNbOfPoints()<<endl;
	return 0;
}
	
