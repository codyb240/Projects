/********************************************************
*	File name:	IP Address Conversion.cpp
*	Author:		Cody Bruehl
*	Date:		10/15/21
*	Class:		CS3013
*	Purpose:	IP Address Conversion
********************************************************/

#include <iostream>
using namespace std;

// this function is used to convert the ip to 8 bit binary string
string binary(unsigned char a)
{
    string b = "";
    while(a > 0){
        b = (a % 2 == 0? '0': '1') + b;
        a /= 2;
    }
    string c = "";
    for(int i = 1; i <= 8 - b.size(); i++){
        c += '0';
    }
    return c + b;
}
int main()
{
    string ipaddress;
    // execute infinite loop
    while(true){
        cout << "Enter an IP v4 address: ";
        cin >> ipaddress;
        unsigned int a = 0;
        unsigned int byte = 0;
        int shift = 24;
        // separates from ip string and stores to 4 byte unsigned int
        for(int i = 0; i < ipaddress.size(); i ++){
            if(ipaddress[i] == '.'){
                a |= byte << shift;
                byte = 0;
                shift -= 8;
            }else{
                byte = 10 * byte + (ipaddress[i] - '0');
            }
        }
        a |= byte;
        
        char* c = (char*)&a;
        
        // calls binary function of ip to print in binary
        for(int i = 3; i >= 0; i--){
            cout << binary(*(c + i));
            cout << " ";
        }
        // prints ip in decimal format
        cout << endl << a << endl;
        
        // asks the user if they would like to try again
        cout<<"Do it again? " << endl;
        char x;
        cin >> x;
        // user says no, break loop
        if(x != 'y') break;
    }
    cout<< "Thank you! Bye!";
        return 0;

}
