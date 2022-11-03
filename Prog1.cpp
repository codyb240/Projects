// Author: Cody Bruehl
// Course: Computer Org/Arch, Spring 2020
// Program: 1
// This program computes the perimeter and area of a rectangle. All calculations are done in
// Intel assembly language.
//-------------------------------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
unsigned short length, width, perim, area; // 16-bit global variables
//-------------------------------------------------------------------------------------------------------------------------
int main(){
 cin >> length; 
 cin >> width;
 // input the length and width in C++
asm(
  " movw length, %ax; " // assembly instructions
  " imulw $2, %ax; "
  " movw width, %bx; " 
  " imulw $2, %bx; "
  " addw %ax, %bx; "
  " movw %bx, perim; "
  " movw length, %cx; "
  " movw width, %dx; "
  " imulw %cx, %dx; "
  " movw %dx, area; " 
 
);
 cout << perim << endl;
 cout << area << endl;
 
 return 0;
}
 
