#pragma once
#include "Item.h"
#include "Cell.h"
ref class Beeper :
	public Item
{

private:
	
	System::Drawing::Bitmap^ beeperBmp1 = gcnew System::Drawing::Bitmap(L"beeper1.bmp");
	
	//System::String ^ file = gcnew System::String("Beeper.txt");
public:
	Beeper();
	bool beeperOn = false;
	
public: 
	System::Drawing::Bitmap^ get_bmp();
	//void get_data(array<Beeper^>^ beeper_array, array<Cell^,2>^ cell_array);
};

