#include <iostream> 
#include <string>
#include <bits/stdc++.h>
using namespace std;

char hx[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

void print_bin(string bin){
	cout << bin << "\t";
}

void print_hex(string hex){
	cout << hex;
}

string change_bin_hex(string bin){

	int n = count(bin.begin(), bin.end(), ' ');// counts number of whitespaces
	remove(bin.begin(), bin.end(), ' ');// removes all whitespaces
	
	int a = bin.length();	// stores length of string
    bin.resize(a - n);// resizes the string to be a-n
   
	size_t len = bin.length();
    string hex = string(len / 4, '0');
    size_t hexoffset = 0;
    for (size_t i = 0; i < len; i += 4) {
        int val = 0;
        for (size_t j = 0; j < 4; j++) {
            if (bin[i + j] == '1') {
                val += (1 << (3 - j));
            }
        }
        hex[hexoffset++] = hx[val];//converts the string bin into hex numbers
    } 
		return hex; //return hex numbers
    
}

string create_bin_string(int z)
{
	string bin;
    
    for(int i=7; i >= 0; i--){ // int size assumed to be 8 bits
		int k = z >> i;
		
        if (k & 1){
            bin = bin + "1";
        }else{
            bin = bin + "0";//generates a binary string
        }  
        if(i == 4){
        	bin = bin + " ";//adding space for output aesthetics 	
		}
    }
   
    print_bin(bin);//print bin
    print_hex(change_bin_hex(bin)); //print hex
	return bin;
}

int main(){
	
	for(int b=0; b < 256; b++){//generating numbers between 0 and 255
		cout << b << "\t";
		create_bin_string(b);
		cout << endl;
	}
	return 0;
}
