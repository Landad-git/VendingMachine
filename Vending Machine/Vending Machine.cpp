// Vending Machine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "VendingSlot.h"
#include <string>
using namespace std;

//constants
const int MAX_COLUMNS = 8;
const int MAX_ROWS = 5;
const int MAX_SLOTS = MAX_ROWS * MAX_COLUMNS;


//strings
string input;

//ints
int slotToGet;

//objects
VendingSlot slot[MAX_SLOTS];

//booleans
bool buying = true;

//prototypes
int calcIndex(int input);
void getInput();

//food symbols
char one = int(185);



int calcIndex(){
	int left = input[0];
	int right = input[1];
	left -= 48;
	right -= 48;

	return(   ((left-1) * MAX_COLUMNS + right - 1)   );


}

void getInput(){
	int left;
	int right;
	bool good = false;


	while (good == false){
		cout << "\nWhich item would you like?";
		cin >> input;

		if(input.length() == 2){
			left = input[0];
			right = input[1];
			left -= 48;
			right -= 48;
			
			if(left > 0 && left <= MAX_ROWS){
				
				if(right > 0 && right <= MAX_COLUMNS){
					
					good = true;
				}
			}
		}
	}

	

}


int _tmain(int argc, _TCHAR* argv[])
{

	
	

	

	//Set each slot number
	int slotCounter = 0;
	for(int i = 0; i < MAX_ROWS; i ++)
	{
		for(int j = 0; i < MAX_COLUMNS; i++){
			
			slot[slotCounter].setSlotNumber((i*10) + j);
			slotCounter++;
		}
	}




	//Fill each slot with an item




	while (buying == true){
		getInput();
		slotToGet = calcIndex();
		cout << "\nInput: " << input << "\nSlot Number: " << slotToGet;
	}


	return 0;
}

