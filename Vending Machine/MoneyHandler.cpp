#include "StdAfx.h"
#include "MoneyHandler.h"


MoneyHandler::MoneyHandler(void)
{
	//LOOP USER INPUT
	/* Add dollar or change
	*/


	//CHANGE CALCULATION
	//Add one to pennies
	/*
	change = moneyIn - moneySpent
	quarters = change % 0.25;
	change -= quarters * 0.25;
	dimes = change % 0.10;
	change -= dimes * 0.10;
	nickels = change % 0.05;
	change -= nickels * 0.05;
	pennies = change * 100;

	*/
}


MoneyHandler::~MoneyHandler(void)
{
}
