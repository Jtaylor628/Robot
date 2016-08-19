#include "robot.h"

void robot::move_robot(array<Item^, 2>^ cell_array)
{
	this->last_move = dir;
	count += 1;
	if (count == 13)
	{
		count = random->Next(1, 5);	//between 4 and 13 moves robot picks a new direction.
		dir = random->Next(1, 4);
		
	}
	
	//If at Top, choose new direction
	if (get_y() == 0)
	{
			dir = 2;
	}
	//If at left edge
	else  if (get_x() == 0)
	{
		dir = 2;
	 }
	else  if (get_x() == 11)
	{
		dir = 4;
	}
	  if (get_y() == 11)
	{
		dir = 1;
	}
	 if ((get_y() == 11) && (get_x() == 0)) 
	 {
		 dir = 1;
	 }
	 if ((get_y() == 0) && (get_x() == 0))
	 {
		 dir = 3;
	 }
	 if ((get_y() == 0) && (get_x() == 11))
	 {
		 dir = 3;
	 }
	 

		switch (dir)
		{
		case 1:if (last_move == 3)
		{
			dir = 2;
		}
			else if (!cell_array[get_x(), get_y() - 1]->wall)
			{
			this->set_y(get_y() - 1);	//check for wall before going direction.
		}
			   else dir = random->Next(1, 4);

			break;
		case 2:if (last_move == 4)
		{
			dir = 3;
		}
			else if (!cell_array[get_x() + 1, get_y()]->wall)
			{
			this->set_x(get_x() + 1);

		}
			   else dir = random->Next(1, 4);
			break;
		case 3:if (last_move == 1)
		{
			dir = 4;
		}
			else if (!cell_array[get_x(), get_y() + 1]->wall)
			{
			this->set_y(get_y() + 1);
				
		}
			   else dir = random->Next(1, 4);
			   
			break;
		case 4:if (last_move == 2)
		{
			dir = 1;
		}
			else if (!cell_array[get_x() - 1, get_y()]->wall)
			{
			this->set_x(get_x() - 1);
		}
			   else dir = random->Next(1, 4);
			   
			break;
		default:
			break;
		}
		if (cell_array[this->get_x(), this->get_y()]->beeper == true)
		{
			this->Beeper_Bag += 1;
			cell_array[this->get_x(), this->get_y()]->beeper = false;
			
		}
}

void robot::player_move(array<Item^, 2>^ cell_array, int move)
{
	if (move == 1 && get_y() == 0) {
		//if at the top, do nothing
	}
	else if (move == 1 && (!cell_array[get_x(), get_y() - 1]->wall)) {
		this->set_y(get_y() - 1);
		this->dir = 1;
	}
	if (move == 2  && get_x() == 11) {
		//if at the top, do nothing
	}
	else if (move == 2 && (!cell_array[get_x() + 1, get_y()]->wall)) {
		this->set_x(get_x() + 1);
		this->dir = 2;
	}
	if (move == 3 && get_y() == 11) {
		//if at the top, do nothing
	}
	else if (move == 3 && (!cell_array[get_x() , get_y() + 1]->wall)) {
		this->set_y(get_y() + 1);
		this->dir = 3;
	}
	if (move == 4 && get_x() == 0) {
		//if at the top, do nothing
	}
	else if (move == 4 && (!cell_array[get_x() - 1, get_y()]->wall)) {
		this->set_x(get_x() - 1);
		this->dir = 4;
	}
}

robot::robot()
{
	
}

System::Drawing::Bitmap^ robot::get_bmp()
{
	if (this->dir == 1)
		return arrow_up;
	if (this->dir == 2)
		return arrow_right;
	if (this->dir == 3)
		return arrow_down;
	if (this->dir == 4)
		return arrow_left;

	return arrow_up;
}
