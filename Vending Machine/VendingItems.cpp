#include "stdafx.h"
#include "VendingItems.h"
#include <string>
#include "LFSR.h"

using namespace std;


VendingItems::VendingItems(){
	void itemCreate(int number);

	itemCreate();



		void itemCreate(int number) {

			VendingItems::VendingItems item;
			item.number = number;
			string.name = NameList();
			item.price = PriceList();

		};

		void generateItems() {

			LFSR lfsr("01101000010", 28);

			for (int i = 0; i < 28; i++)
				int bit = lfsr.step();


			for (int i = 0; i < 28; i++) {
				for (int j = 0; j < 28; j++) {
					number = lfsr.generate(j);
					itemCreate(number, i);
				};
			};
		};
}