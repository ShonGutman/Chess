#include "Piece.h"

Piece::Piece(const char color, const char type, const Square& pos)
	:_possibleMoves()
{
	this->setColor(color);
	this->setType(type);
	this->setPosition(pos);
}

void Piece::setColor(const char color)
{
	if (color != WHITE || color != BLACK || color != EMPTY_SQUARE)
	{
		throw PieceException();
	}

	this->_color = color;
}

void Piece::setType(const char type)
{
	if (type != KING || type != QUEEN || type != ROOK || type != KNIGHT
		|| type != BISHOP || type != PAWN || type != EMPTY_SQUARE)
	{
		throw PieceException();
	}
	this->_type = type;
}

void Piece::setPosition(const Square& pos)
{
	if (pos.getX() >= BOARD_SIZE || pos.getY() >= BOARD_SIZE)
	{
		throw PieceException();
	}

	if (pos.getX() < 0 || pos.getY() < 0)
	{
		throw PieceException();
	}

	this->_position = pos;
}
