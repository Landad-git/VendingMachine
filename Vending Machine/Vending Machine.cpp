// Vending Machine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "VendingSlot.h"
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
//NEW
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//constants
const int MAX_COLUMNS = 8;
const int MAX_ROWS = 5;
const int MAX_SLOTS = MAX_ROWS * MAX_COLUMNS;

//chars
char r = int(205);
char w = int(186);
char s = ' ';
//strings
string input;
//NEW
char displayMachine[1197] = {r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
						w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,
						r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
						w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,s,s,s,s,s,s,s,s,s,s,s,s,s,w,
						r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,s,s,s,s,s,s,w,
						r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,};


string chips[8] = {"PLCH", "DRTS", "CHET", "VEGI", "LAYS", "FRIT", "PRTZ", "BUGL"};
string drink[4] = {"COKE", "FNTA", "SPRT", "WATR"};
string snacks[8] = {"ALTD", "SKIT", "M&Ms", "SNIK", "ORBT", "WGUM", "TGUM", "STRB"};

double price[6] = {1.50, 1.75, 1.75, 2.00, 1.00, 1.25};
//ints
int slotToGet;

//objects
VendingSlot slot[MAX_SLOTS];

//booleans
bool buying = true;

//prototypes
int calcIndex(int input);
void getInput();
void displayMachines();//NEW
void setCursor(int coordX, int coordY);
void initializeMachine();
void displaySlots();
void fillChips();
void fillDrinks();
void fillSnacks();
//food symbols


//misc
COORD coord;


int calcIndex(){
	//represents row number
	int left = input[0];
	//represents column number
	int right = input[1];

	//adjusts for ASCII problems
	left -= 48;
	right -= 48;

	//returns a value that is the user input in format of row + column into a contiguous slot number
	return(   ((left-1) * MAX_COLUMNS + right - 1)   );


}

void setCursor(int coordX, int coordY) {
	coord.X = coordX;
	coord.Y = coordY;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getInput(){
	int left;
	int right;
	bool good = false;
	

	while (good == false){
		setCursor(0,21);
		cout << "\nWhich item would you like?   ";
		cin >> input;
		//checks for user input being correct length
		if(input.length() == 2){
			//converts input into rows and columns
			left = input[0];
			right = input[1];
			left -= 48;
			right -= 48;
			
			int realSlot = calcIndex();
			//determines if the rows/columns are valid
			if(left > 0 && left <= MAX_ROWS){
				
				if(right > 0 && right <= MAX_COLUMNS){
					
					if(slot[realSlot].getSlotQuantity() == 0)
						cout << "Product not available";

					good = true;
				}
			}
		}
	}

	

}

void displayMachines(){
	for(int i = 0; i < sizeof(displayMachine); i++){
		
		if(i%57==0)
			cout << "\n";
		cout << displayMachine[i];
	}
}

void initializeMachine(){
	
	int slotCounter = 0;
	for(int i = 0; i < MAX_ROWS; i++)
	{
		
		for(int j = 0; j < MAX_COLUMNS; j++){
			
			slot[slotCounter].setSlotNumber((i*10) + j);
			
			slotCounter++;
		}
	}
}

void displaySlots(){
	
	
	int slotCounter = 0;
	for(int i = 0; i < MAX_ROWS; i++)
	{
		for(int j = 0; j < MAX_COLUMNS; j++){
			//i = y = rows, j = x = columns



			if(slot[slotCounter].getSlotPrice() != 0)
			{

			if(slotCounter > 15){
			setCursor( (j*7+3),(i*4+2) );
			cout <<  i+1 << j+1;
			setCursor( (j*7+2),(i*4+3) );
			cout << slot[slotCounter].getSlotItem();
			setCursor( (j*7+2),(i*4+4) );
			cout << setprecision(2) << fixed << slot[slotCounter].getSlotPrice();
			}
			else {
				setCursor( (j*7+7),(i*4+2) );
				cout <<  i+1 << j+1;
				setCursor( (j*7+6),(i*4+3) );
				cout << slot[slotCounter].getSlotItem();
				setCursor( (j*7+6),(i*4+4) );
				cout << setprecision(2) << fixed << slot[slotCounter].getSlotPrice();
			}
			}
			slotCounter++;
		}
	}
	
}

void fillChips(){
	for(int i = 0; i < 15; i +=2){
		slot[i].setSlotItem(chips[rand() % 8]);
		slot[i].setSlotPrice(price[rand() % 2]);
		slot[i].setSlotQuantity(rand() % 8 + 1);
	}
}

void fillDrinks(){
	for(int i = 16; i <= 23; i++){
		slot[i].setSlotItem(drink[rand() % 4]);
		slot[i].setSlotPrice(price[rand() % 2 + 2]);
		slot[i].setSlotQuantity(rand() % 8 + 1);
	}
}

void fillSnacks(){
	for(int i = 24; i < 40; i++){
		slot[i].setSlotItem(snacks[rand() % 8]);	
		slot[i].setSlotPrice(price[rand() % 2 + 4]);
		slot[i].setSlotQuantity(rand() % 8 + 1);
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	//sets random seed
	unsigned srand(time(NULL)); 

	//sets each slow to default settings
	initializeMachine();
	
	//Show the outline of the machine
	displayMachines();
	

	//fills all the chips slots 
	fillChips();

	//fills all the drink slots
	fillDrinks();

	//fills all the snack slots
	fillSnacks();

	//shows EVERYTHING
	displaySlots();

	//pandaserver.dtdns.net

	

	




	while (buying == true){
		getInput();
		slotToGet = calcIndex();
		cout << "\nInput: " << input << "\nSlot Number: " << slotToGet;
	}


	return 0;
}

