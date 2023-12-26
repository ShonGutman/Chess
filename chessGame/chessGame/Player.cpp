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

int Player::play(std::string move)
{
	return 0;
}
