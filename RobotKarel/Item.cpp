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









