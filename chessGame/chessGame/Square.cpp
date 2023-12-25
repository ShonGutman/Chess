#include "Square.h"

Square::Square()
{
	_x = 0;
	_y = 0;
}

Square::Square(const int x, const int y)
{
	if (x >= BOARD_SIZE || x < 0 || y >= BOARD_SIZE || y < 0)
	{
		throw "Can't create a square out of board";
	}
	_x = x;
	_y = y;
}

Square::~Square()
{
}

int Square::getX() const
{
	return _x;
}

int Square::getY() const
{
	return _y;
}

Square& Square::operator=(const Square& other)
{
	_x = other._x;
	_y = other._y;
}
