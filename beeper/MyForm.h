#pragma once
#include "Item.h"


ref class Beeper : public Item
{
	/* 

	protected static System::Drawing::Icon^ beeper;
	*/
	int row, col, numbeep;

public: Beeper(void);
		Beeper(int);

		//Accessors
		int getRow();
		int getCol();
		int getBeepNum();

};