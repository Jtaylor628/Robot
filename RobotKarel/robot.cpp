#include "robot.h"



/*System::Drawing::Icon^ robot::getIcon()
{
	return arrowUp;
	
}*/




void robot::move_robot(int direction)
{
	this->set_x(get_x() - 1);
}

robot::robot()
{
	
}
