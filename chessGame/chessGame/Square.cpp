#include "Square.h"

Square::Square()
{
	_x = 0;
	_y = 0;
}

Square::Square(const int x, const int y)
{
	this->setSquare(x,y);
}

Square::Square(const Square& other)
{
	this->setSquare(other.getX(),other.getY());
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

void Square::setSquare(const int x, const int y)
{
	if (!Square::checkSquare(x, y))
	{
		throw GameException("Can't create a square out of board!");
	}
	_x = x;
	_y = y;
}

Square& Square::operator=(const Square& other)
{
	_x = other._x;
	_y = other._y;
	return *this;
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

bool Square::IncX()
{
	if (_x < BOARD_SIZE - 1)
	{
		_x++;
		return true;
	}
	return false;
}

bool Square::IncY()
{
	if (_y < BOARD_SIZE - 1)
	{
		_y++;
		return true;
	}
	return false;
}

bool Square::DecX()
{
	if (_x > 0)
	{
		_x--;
		return true;
	}
	return false;
}

bool Square::DecY()
{
	if (_y > 0)
	{
		_y--;
		return true;
	}
	return false;
}

bool Square::checkSquare(const int x, const int y)
{
	if (x >= BOARD_SIZE && x < 0 && y >= BOARD_SIZE && y < 0)
	{
		return false;
	}

	return true;
}

bool Square::getSqu(std::string& move, Square& squ)
{
	int cord[SQUARE_STRING_LENGTH] = {0,0};
	if (move.length() != SQUARE_STRING_LENGTH)
	{
		throw GameException("Square string not in format!");
	}
	for (int i = 0; i < SQUARE_STRING_LENGTH; i++)
	{
		char temp = move[i];
		if (isalpha(temp))
		{
			if (int(temp) >= int('a') && int(temp) <= int('h'))
			{
				cord[i] = int(temp) - int('a');
			}
			else
			{
				return false;
			}
		}
		else if (isdigit(temp))
		{
			if (int(temp) >= int('0') && int(temp) <= int(BOARD_SIZE + '0'))
			{
				cord[i] = int(BOARD_SIZE + '0') - int(temp);
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	try
	{
		squ.setSquare(cord[1], cord[0]);
	}
	catch (GameException& e)
	{
		return false;
	}
	return true;
}


