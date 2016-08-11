#pragma once
#include "Item.h"
ref class Cell :
	public Item
{
public:
	int numrows;
	int numbcol;
	//array <Item^, 2>^ maze;

	Cell();
};

