#include "Stdafx.h"
#include "VendingSlot.h"
#include <string>

using namespace std;

VendingSlot::VendingSlot(){

	int slotNumber = 0;
	double slotPrice = 0;
	int slotQuantity = 0;
	string slotItem = "";
}
/****************************************/
void VendingSlot::setSlotNumber(int input){
	VendingSlot::slotNumber = input;
}

int VendingSlot::getSlotNumber(void) const
	{return VendingSlot::slotNumber;}

/****************************************/

void VendingSlot::setSlotItem(string input){
	VendingSlot::slotItem = input;
}

string VendingSlot::getSlotItem(void) const
	{return VendingSlot::slotItem;}

/****************************************/

void VendingSlot::setSlotPrice(double input){
	VendingSlot::slotPrice = input;
}

double VendingSlot::getSlotPrice(void) const
	{return VendingSlot::slotPrice;}

/****************************************/

void VendingSlot::setSlotQuantity(int input){
	VendingSlot::slotQuantity = input;
}

int VendingSlot::getSlotQuantity(void) const
	{return VendingSlot::slotQuantity;}


/****************************************/