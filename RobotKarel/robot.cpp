#include "robot.h"



/*System::Drawing::Icon^ robot::getIcon()
{
	return arrowUp;
	
}*/




void robot::move_robot(array<Item^, 2>^ cell_array)
{
	count += 1;
	if (count == 13) {
		count = random->Next(3, 13);	//between 1 and 10 moves robot picks a new direction.
		dir = random->Next(1, 4);
		
	}
	
	//int dir = random->Next(1,4);

	
	//If at Top, choose new direction
	if (get_y() == 0) {
			dir = 2;
	}
	//If at left edge
	else  if (get_x() == 1) {
		dir = 2;
	 }
	else  if (get_x() == 15) {
		dir = 4;
	}
	else  if (get_y() == 15) {
		dir = 1;
	}
	 if ((get_y() == 15) && (get_x() == 1)) {
		 dir = 1;
	 }
	 if ((get_y() == 0) && (get_x() == 1)) {
		 dir = 3;
	 }
	 if ((get_y() == 0) && (get_x() == 15)) {
		 dir = 3;
	 }




		switch (dir)
		{
		case 1:if (!cell_array[get_x(), get_y() - 1]->wall) {
			this->set_y(get_y() - 1);
		}
			break;
		case 2:if (!cell_array[get_x() + 1, get_y()]->wall) {
			this->set_x(get_x() + 1);
		}//this->set_x(get_x() + 1);
			break;
		case 3:if (!cell_array[get_x(), get_y() + 1]->wall) {
			this->set_y(get_y() + 1);
		}//this->set_y(get_y() + 1);
			break;
		case 4:if (!cell_array[get_x() - 1, get_y()]->wall) {
			this->set_x(get_x() - 1);
		}//this->set_x(get_x() - 1);
			break;
		default:
			break;
		}
		
}

robot::robot()
{
	
}
