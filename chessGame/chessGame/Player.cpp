#include "Player.h"

Player::Player()
{
	throw GameException("Can't create empty player!");
}

Player::Player(const char color, Board* chessBoard)
{
	if (color == WHITE)
	{
		_color = WHITE;
		_isMyTurn = true;
		_chessBoard = chessBoard;
	}
	else if(color == BLACK)
	{
		_color = BLACK;
		_isMyTurn = false;
		_chessBoard = chessBoard;
	}
	else
	{
		throw GameException("Can't create a colorfull player!");
	}
}

Player::~Player()
{
}

Board& Player::getBoard() const
{
	return *this->_chessBoard;
}

bool Player::getTurn() const
{
	return _isMyTurn;
}

void Player::setTurn()
{
	if(_isMyTurn)
	{
		_isMyTurn = false;
	}
	else
	{
		_isMyTurn = true;
	}
}

int Player::play(std::string move)
{
	int cord[MOVE_STRING_LENGTH] = {0,0,0,0};
	if (move.length() != MOVE_STRING_LENGTH)
	{
		throw GameException("Move string not in format!");
	}
	for (int i = 0; i < MOVE_STRING_LENGTH; i++)
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
				return OUT_OF_BOARD;
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
				return OUT_OF_BOARD;
			}
		}
		else
		{
			return OUT_OF_BOARD;
		}
	}
	Square squFrom;
	Square squTo;
	try
	{
		squFrom.setSquare(cord[1], cord[0]);
		squTo.setSquare(cord[3], cord[2]);
	}
	catch (GameException& e)
	{
		return OUT_OF_BOARD;
	}
	return _chessBoard->move(squFrom, squTo, _color);
}
