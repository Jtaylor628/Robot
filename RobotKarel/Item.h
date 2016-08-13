#pragma once


ref class Item
{
private:
	//System::String^ file = gcnew System::String("Beeper.txt");
	int x1 = 0;
	int y1 = 0;
	bool beeper = false;
	bool wall = false;
	//static System::String ^ str = gcnew System::String("sdf");
	//public:System::String^ file = gcnew System::String("Beeper.txt");
	
public:

	Item();
	void set_x(int x);
	void set_y(int y);
	int get_x();
	int get_y();
	void get_data(array<Item^>^ beeper_array, array<Item^, 2>^ cell_array);
	
};

