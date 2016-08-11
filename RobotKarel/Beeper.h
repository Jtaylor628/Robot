#pragma once
#include "Item.h"
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
public: void set_x(int x);
	void set_y(int y);
};

