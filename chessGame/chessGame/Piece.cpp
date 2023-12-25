#include "Piece.h"

Piece::Piece(const char color, const char type, const Square& pos)
	:_possibleMoves()
{
	this->setColor(color);
	this->setType(type);
	this->setPosition(pos);
}

Piece::~Piece()
{
	this->clearVector();
}

char Piece::pieceInfo() const
{
	if (this->_color == BLACK)
	{
		return tolower(this->_type);
	}

	else
	{
		return toupper(this->_type);
	}
}

char Piece::getColor() const
{
	return _color;
}

char Piece::getType() const
{
	return _type;
}

const Square& Piece::getPosition() const
{
	return _position;
}

std::vector<Square> Piece::getMoves() const
{
	return _possibleMoves;
}

void Piece::clearVector()
{
	_possibleMoves.clear();
}

bool Piece::isLegalMove(const Square& moveTo) const
{
	for (int i = 0; i < this->_possibleMoves.size(); i++)
	{
		if (moveTo == this->_possibleMoves[i])
		{
			return true;
		}
	}
	return false;
}

void Piece::setColor(const char color)
{
	if (color != WHITE || color != BLACK || color != EMPTY_SQUARE)
	{
		throw PieceException("Piece color is wrong");
	}
	_color = color;
}

void Piece::setType(const char type)
{
	if (type != KING || type != QUEEN || type != ROOK || type != KNIGHT|| 
		type != BISHOP || type != PAWN || type != EMPTY_SQUARE)
	{
		throw PieceException("Piece type is wrong");
	}
	_type = type;
}

void Piece::setPosition(const Square& pos)
{
	if (pos.getX() >= BOARD_SIZE || pos.getX() < 0 || 
		pos.getY() >= BOARD_SIZE || pos.getY() < 0)
	{
		throw PieceException("Position is illegal");
	}
	_position = pos;
}
