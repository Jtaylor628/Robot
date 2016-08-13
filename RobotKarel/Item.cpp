#include "Item.h"
#include <string>;
#include <fstream>;

using namespace System::Windows::Forms;

//#include <msclr\marshal_cppstd.h>;

Item::Item()
{
}

void Item::set_x(int x)
{
	x1 = x;
}

void Item::set_y(int y)
{
	y1 = y;
}

int Item::get_x()
{
	return x1;
}

int Item::get_y()
{
	return y1;
}

void Item::get_data(array<Item^>^ beeper_array, array<Item^, 2>^ cell_array)
{
	

	std::string file = "stuff.txt";
	//System::String^ managedString = "test";

	//msclr::interop::marshal_context context;
	//std::string file1 = context.marshal_as<std::string>(this->file);

	//file = msclr::interop::marshal_as<std::string>(this->file);
	int number_ofThings = 0;
	int x = 0;
	int y = 0;
	std::string str;
	std::ifstream in_stream;
	in_stream.open(file);
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
			beeper_array[i]->x1 = x;
			in_stream >> y;
			beeper_array[i]->y1 = y;
			//if(str == "beeper")
			//cell_array[x, y]->beeper = true;

		}
		//count++;
	}


}




