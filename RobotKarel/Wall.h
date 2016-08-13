#pragma once
#include "Item.h"
#include "Cell.h"
ref class Wall :
	public Item

{
private:
	array <Wall^>^ Wall_array;
	int wall_array_size = 5;
	int x1 = 0;
	int y1 = 0;
public:
	Wall();
	//Wall(array<Cell^, 2>^ cell_array);
	
	
};

