#include "robot.h"



System::Drawing::Icon^ robot::getIcon()
{
	return arrowUp;
	
}

robot::robot(int x, int y)
{
	this->x = x;
	this->y = y;
}
