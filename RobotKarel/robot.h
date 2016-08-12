#pragma once
ref class robot
{
private:
	int x;
	int y;
	static System::Drawing::Icon^ arrowUp = gcnew System::Drawing::Icon("arrowUp.ico");
public:
	System::Drawing::Icon^ robot::getIcon();
	robot(int z, int y);


};

