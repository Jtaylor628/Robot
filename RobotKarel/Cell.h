#pragma once
#include "Item.h"
ref class Cell :
	public Item
{
public:
	int numrows;
	int numbcol;
	bool beeper = false;
	bool wall = false;
	//array <Item^, 2>^ maze;

	Cell();
};

