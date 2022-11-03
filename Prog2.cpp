#include <iostream>
using namespace std;
int a, b, sum = 0; // 32-bit global variables
//-------------------------------------------------------------------------------------------------------------------------
int main()
{
 cin >> a;
 cin >> b;
 // input the integers a and b
asm(
  "movl a, %eax    ;"	// moves a to eax register 

 "cmpl %eax, b     ;"	// compares a to b
 "jl done          ;"   // jumps to done to close assembly
 
 "top:             ;"	// top of loop
 "addl %eax,sum    ;"	//adds a to sum
 "incl %eax        ;"	//increases a by one
 "cmpl b, %eax     ;"	//compares b to a until it =
 "jle top          ;"   //if a < b jumps to top

 "done:            ;"
);
 cout << sum << endl; // output the sum // if a > b, zero will be printed for the sum
 return 0;
}
