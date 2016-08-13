#include "Wall.h";
#include <fstream>;
#include <string>;
using namespace System::Windows::Forms;
Wall::Wall() {
}

/*Wall::Wall(array<Cell^, 2>^ cell_array)
{
	Wall_array = gcnew array<Wall^>(wall_array_size);
	for (int i = 0; i < wall_array_size; i++) {
		Wall_array[i] = gcnew Wall();


		int number_ofThings = 0;
		int x = 0;
		int y = 0;
		std::string str;
		std::ifstream in_stream;
		in_stream.open("Wall.txt");
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
				x1 = x;
				in_stream >> y;
				y1 = y;
				cell_array[x, y]->wall = true;

			}
	}
}*/

	
