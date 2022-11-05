/*------------------------------------------------
Programmer:		Cody Bruehl
Professor:		Zhao
Date:			02/12/2022
Purpose:
This program allows one user to play battleship
against a randomly generated grid of ships.
------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib> 

using namespace std;

//global declarations
// Damage enum defines possible values at each grid point.
enum Damage {Empty, Miss, Occupied , Hit};

// The display array defines what to display for
//     each of the Damage enum values.  Changes to the
//     Damage enum require this to be changed also.
const char display[] = {'-', 'O', '-', 'X'};

const  int WIDTH = 5;   		// Width of the grid.
const  int HEIGHT= 5;			// Height of the grid.
Damage grid[WIDTH][HEIGHT];     // Records status of every grid cell.

//prototypes
void Payload(int xcoord, int ycoord);
void takeInput(char cmd);
void Grid();
bool gameOver();
void print();

//****************************************************************
int main() {

    srand(time(0));  // Initialize random number generator
    
    char ans;
    do {
        Grid();  // Randomly place ships on the grid.
        print();

		cout << "Press 'p' to play or 'q' to quit: ";
		
        
        char commandCode;
        while (cin >> commandCode) {
       	
        	           cout << "Enter coordinates now for Payload: (x,y): ";
        
            takeInput(commandCode);
            
            
            if (gameOver()) {
                cout << "Congratulations, you win!" << endl;
                break;
            }
        }
        cout << "Do you want to play again? (y/n) ";
        ans = 'n';
        cin >> ans;
    } while (ans == 'y');
    
    return 0;
}

//****************************************************************
// This function tells the program to either quit 
// or continue with letting you drop a bomb.
void takeInput(char cmd) { 		
    switch (cmd) {
        
        case 'q':           // quit
		    cout << "Thanks for playing!" << endl;
            exit(0);
            break;
            
        case 'p':           // bomb
            int xloc, yloc;
            cin >> xloc;
			cin >> yloc;
            if (xloc>=0 && xloc<WIDTH){
				if(yloc >= 0 && yloc < HEIGHT){
				    cout << "Thank you. Payload going out to (x,y) = ("<< xloc << "," << yloc << ")" << endl;
					Payload(xloc, yloc);
				}else{
                  cout << "Error: Y Bombing coordinate must be between 0 and " << HEIGHT-1 << endl;
				}
            } else {
                cout << "Error: X Bombing coordinate must be between 0 and " << WIDTH-1 << endl;
            }
            print();
			cout << "Press 'p' to play or 'q' to quit: ";
            break;
            
        default:            // error
            cerr << "Error: command not recognized. " << endl;
            break;
    }
}

//****************************************************************
// Function for attacking 
void Payload(int xcoord, int ycoord) { 		
    switch (grid[xcoord][ycoord])
	{
    
    case Empty: 
          grid[xcoord][ycoord] = Miss;
          break;
          
    case Occupied: 
          grid[xcoord][ycoord] = Hit;
          break;
    }
    return;
}

//****************************************************************
// This function places random ships on the grid.
void Grid() {
    for (int i=0; i<WIDTH; i++) {  // clear grid
		for(int j = 0; j < HEIGHT; j++){
			grid[i][j] = Empty;
		}
    }

	// Place a 3-cell ship in grid.	
    int startx = rand() % (WIDTH-2); 
	int starty = rand() % (HEIGHT-2);
    grid[startx+0][starty+0] = Occupied;
    grid[startx+1][starty+1] = Occupied;
    grid[startx+2][starty+2] = Occupied;
}

//****************************************************************
// This function prints to the screen.
void print() {
    cout << endl;

	cout << setw(2) << " ";
    
    // Print coordinates.
    for (int coord=0; coord<WIDTH; coord++) {
        cout << setw(2) << coord;
    }

	cout << endl;

    for (int i=0; i<WIDTH; i++) {
	    cout << setw(2) << i;
		for(int j = 0; j < HEIGHT; j++){
			cout << " " << display[grid[i][j]];
		}
		cout << endl;
    }
    
    cout << endl << endl;
}

//****************************************************************
//This function tells you when the game is over.
bool gameOver() {
    for (int i=0; i<WIDTH; i++) {
		for(int j = 0; j < HEIGHT; j++){
			if (grid[i][j] == Occupied) {
				return false;
			}
        }
    }
    return true;
}
