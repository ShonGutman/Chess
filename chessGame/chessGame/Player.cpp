#include "Player.h"

Player::Player()
{
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
