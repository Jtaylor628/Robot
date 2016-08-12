#pragma once
#include "Item.h"
#include "Cell.h"
ref class Beeper :
	public Item
{

private:
	int x;
	int y;
public:
	Beeper();
	int get_x();
	int get_y();
public: 
	void set_x(int x);
	void set_y(int y);
	void get_data(array<Beeper^>^ beeper_array, array<Cell^,2>^ cell_array);
};

