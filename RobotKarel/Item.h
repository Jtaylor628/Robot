#pragma once


ref class Item
{
private:
	//System::String^ file = gcnew System::String("Beeper.txt");
	int x1 = 0;
	int y1 = 0;

	
	//static System::String ^ str = gcnew System::String("sdf");
	//public:System::String^ file = gcnew System::String("Beeper.txt");
	
public:
	bool wall = false;
	bool beeper = false;
	Item();
	void set_x(int x);
	void set_y(int y);
	int get_x();
	int get_y();
	
	
};

