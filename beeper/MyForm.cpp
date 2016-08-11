#include "Beeper.h"

Beeper(int beepnum) : Item(newRow, newCol)
{
	row = newRow;
	col = newCol;
	numbeep = beepnum;
}

int Beeper::getRow()
{
	return row;
}

int Beeper::getCol()
{
	return col;
}

int Beeper::getBeepNum()
{
	return numbeep;
}