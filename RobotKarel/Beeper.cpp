#include "Beeper.h";
//#include <fstream>;
//#include <string>;
#include "Cell.h";
using namespace System::Windows::Forms;

Beeper::Beeper()
{


}

System::Drawing::Bitmap ^ Beeper::get_bmp()
{
	
	return beeperBmp1;
	
	// TODO: insert return statement here
}








/*void Beeper::get_data(array<Beeper^>^ beeper_array, array<Cell^,2>^ cell_array)
{
	std::string file = "stuff.txt";
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
			beeper_array[i]->set_x(x);
			in_stream >> y;
			beeper_array[i]->set_y(y);
			cell_array[x, y]->beeper = true;
			
		}
		//count++;
	}


}*/
