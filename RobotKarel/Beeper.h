#pragma once
#include "Item.h"
#include "Cell.h"
ref class Beeper :
	public Item
{

private:
	
	System::Drawing::Bitmap^ beeperBmp1 = gcnew System::Drawing::Bitmap(L"beeper1.bmp");
	
public:
	Beeper();
	bool beeperOn = false;
	
public: 
	System::Drawing::Bitmap^ get_bmp();
};

