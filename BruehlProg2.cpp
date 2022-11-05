/*-------------------------------------------------------------
Programmer:		Cody Bruehl
Professor:		Moinian
Assignment:		Prog 2
Purpose:
The purpose of this program is to utilize the brute force method 
for decrypting a given users password. The program will then
output the decrypted password and the number of passwords
that it tried prior to getting to the correct one.
-------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

char alph[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char crypt[] = {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1'};

int decrypt(string cryptpw){
	char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	string pw = "aaaa00";
	int counter = 0;
		for(int a=0; a < 26; a++){
			for(int b=0; b < 26; b++){
				for(int c=0; c < 26; c++){
					for(int d=0; d < 26; d++){
						for(int e=0; e < 10; e++){
							for(int f=0; f < 10; f++){
								counter++;
								pw[5] = num[f];
								pw[4] = num[e];
								pw[3] = abc[d];
								pw[2] = abc[c];
								pw[1] = abc[b];
								pw[0] = abc[a];
								cout << pw << endl;
								if(pw == cryptpw){
									goto label;
								}
							}
						}
					}
				}
			}
		}
	label:
	for(int k = 0; k < 7; k++){
		for(int j=0; j < 36; j++){
			if(pw[k] == crypt[j]){
				pw[k] = alph[j];
				break;
			}
		}
	}
	cout << "Password: " << pw << endl;
	cout << "Number of incorrect password tries: " << counter << endl;
}

int main(){
	int i = 0;
	string username;
	string users[] = {"cody", "dillion", "jeff", "joseph", "luke", "paul", "preston", "robert", "ryan", "sammie"};
	string cryptpw[] = {"dtqg21", "ejku83", "yctf53", "gidg74", "oeng86", "ygdd03", "oggm77", "pcuj13", "eqzz70", "rqyg78"};
	
	cout << "Password Recovery Tool" << endl;
	cout << "Username: ";
	cin >> username;
	
	for(i ; i < 10; i++){
		if(users[i] == username){
			break;
		}
	}
	if(i == 10){
		cout << "Login not found!" << endl;
		return 0;
	}
	
	cout << "Login: " << username[i] << endl;
	decrypt(cryptpw[i]);
	
	return 0;
}
