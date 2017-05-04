#pragma once
#ifndef VENDINGSLOT_H
#define VENDINGSLOT_H

#include <string>

using namespace std;

class VendingSlot
{
private:
	int slotNumber;
	double slotPrice;
	int slotQuantity;
	string slotItem;

public:
	VendingSlot(void);

	void setSlotNumber(int input);
	int getSlotNumber() const;

	void setSlotItem(string input);
	string getSlotItem() const;

	void setSlotPrice(double input);
	double getSlotPrice() const;

	void setSlotQuantity(int input);
	int getSlotQuantity() const;


};

#endif

/*


■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
█     █     █     █     █     █     █     █     █
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■










*/