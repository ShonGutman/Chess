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
		throw PieceException("Can't create a square out of board");
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

Square Square::operator+(const Square& other) const
{
	return Square(this->_x + other._x, this->_y + other._y);
}

Square& Square::operator+=(const Square& other)
{
	*this = *this + other;
	return *this;
}

Square Square::operator-(const Square& other) const
{
	return Square(this->_x - other._x, this->_y - other._y);
}

Square& Square::operator-=(const Square& other)
{
	*this = *this - other;
	return *this;
}

bool Square::operator==(const Square& other) const
{
	return this->_x == other._x && this->_y == other._y;
}

bool Square::checkSquare(const int x, const int y)
{
	if (x >= BOARD_SIZE || x < 0 || y >= BOARD_SIZE || y < 0)
	{
		return false;
	}

	return true;
}


