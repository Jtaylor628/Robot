#pragma once
#include "Item.h";
ref class robot : 
	public Item

{
private:
	System::Random^ random = gcnew System::Random();
	int count = 3;
	int dir = 1;
	
	//static System::Drawing::Icon^ arrowUp = gcnew System::Drawing::Icon("arrowUp.ico");
public:
	//System::Drawing::Icon^ robot::getIcon();
	void move_robot(array<Item^, 2>^ cell_array);
	robot();


};

