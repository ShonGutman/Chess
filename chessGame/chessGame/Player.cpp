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

int Player::play(std::string& move)
{
	Square squFrom;
	Square squTo;
	std::string move1 = move.substr(0, SQUARE_STRING_LENGTH);
	std::string move2 = move.substr(SQUARE_STRING_LENGTH, SQUARE_STRING_LENGTH);
	if (!Square::getSqu(move1, squFrom) || !Square::getSqu(move2, squTo))
	{
		return OUT_OF_BOARD;
	}
	move1.clear();
	move2.clear();
	return _chessBoard->move(squFrom, squTo, _color);
}
