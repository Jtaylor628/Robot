#include "Beeper.h";
#include <fstream>;
#include <string>;
#include "Cell.h";
using namespace System::Windows::Forms;

Beeper::Beeper()
{


}

int Beeper::get_x()
{
	return x;
}

int Beeper::get_y()
{
	return y;
}

void Beeper::set_x(int x)
{
	this->x = x;
}

void Beeper::set_y(int y)
{
	this->y = y;
}

void Beeper::get_data(array<Beeper^>^ beeper_array, array<Cell^,2>^ cell_array)
{
	
	int number_ofThings = 0;
	int x = 0;
	int y = 0;
	std::string str;
	std::ifstream in_stream;
	in_stream.open("stuff.txt");
	if (in_stream.fail()) {
		MessageBox::Show("failed to open file");
		exit(1);
	}
	int count = 0;
	while (!in_stream.eof()) {
		in_stream >> str;
		in_stream >> number_ofThings;
		for (int i = 0; i < number_ofThings; i++) {
			in_stream >> x;
			beeper_array[i]->set_x(x);
			in_stream >> y;
			beeper_array[i]->set_y(y);
			cell_array[x, y]->beeper = true;
			
		}
		//count++;
	}


}
