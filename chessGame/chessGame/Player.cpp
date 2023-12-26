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
	// TODO: insert return statement here
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
	int pos[MOVE_STRING_LENGTH] = {0,0,0,0};
	if (move.length() != MOVE_STRING_LENGTH)
	{
		throw GameException("Move string not in format!");
	}
	for (int i = 0; i < MOVE_STRING_LENGTH; i++)
	{
		char temp = move[i];
		if (isalpha(temp))
		{
			
		}
		else if (isdigit(temp))
		{
			if(int(temp) >= int(0) && int(temp) <= int(9))
			{

			}
		}
		else
		{
			throw GameException("Weird squares in move string");
		}
	}
}
