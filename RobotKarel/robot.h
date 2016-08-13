#pragma once
#include "Item.h";
ref class robot : 
	public Item

{
private:
	
	
	//static System::Drawing::Icon^ arrowUp = gcnew System::Drawing::Icon("arrowUp.ico");
public:
	//System::Drawing::Icon^ robot::getIcon();
	void move_robot(int direction);
	robot();


};

