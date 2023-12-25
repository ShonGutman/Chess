#include "Square.h"

Square::Square(const int x, const int y)
{
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
