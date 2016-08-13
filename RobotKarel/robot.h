#pragma once
#include "Item.h";
ref class robot : 
	public Item

{
private:
	System::Random^ random = gcnew System::Random();
	int count = 3;
	int dir = 1;
	System::Drawing::Bitmap^ arrow_up = gcnew System::Drawing::Bitmap(L"arrowUp.bmp");
	System::Drawing::Bitmap^ arrow_right = gcnew System::Drawing::Bitmap(L"arrowRight.bmp");
	System::Drawing::Bitmap^ arrow_down = gcnew System::Drawing::Bitmap(L"arrowDown.bmp");
	System::Drawing::Bitmap^ arrow_left = gcnew System::Drawing::Bitmap(L"arrowLeft.bmp");
	//static System::Drawing::Icon^ arrowUp = gcnew System::Drawing::Icon("icon2.ico");
public:
	//System::Drawing::Icon^ robot::getIcon();
	
	void move_robot(array<Item^, 2>^ cell_array);
	robot();
	System::Drawing::Bitmap^ get_bmp();

};

