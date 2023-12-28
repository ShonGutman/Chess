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

void Piece::move(const Square& newPos)
{
	if (isLegalMove(newPos))
	{
		this->_pos = newPos;
	}
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
	return _pos;
}

std::vector<Square> Piece::getMoves() const
{
	return _possibleMoves;
}

void Piece::clearVector()
{
	_possibleMoves.clear();
}

char Piece::opColor(const char color)
{
	if (color == WHITE)
	{
		return BLACK;
	}

	else if (color == BLACK)
	{
		return WHITE;
	}

	else if (color == EMPTY_SQUARE)
	{
		std::cerr << "WARNING: tried to get color of empty square";
		return EMPTY_SQUARE;
	}
	
	throw(GameException("Color can only Black or White"));
}

bool Piece::isLegalMove(const Square& moveTo) const
{
	return Piece::isLegalMove(moveTo, this->_possibleMoves);
}

bool Piece::isLegalMove(const Square& moveTo, std::vector<Square> possibleMoves)
{
	for (int i = 0; i < possibleMoves.size(); i++)
	{
		if (moveTo == possibleMoves[i])
		{
			return true;
		}
	}
	return false;
}

void Piece::setPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	this->_possibleMoves = this->findNewPossibleMoves(chessBoard);
}

void Piece::setColor(const char color)
{
	if (color != WHITE && color != BLACK && color != EMPTY_SQUARE)
	{
		throw GameException("Piece color is wrong!");
	}
	_color = color;
}

void Piece::setType(const char type)
{
	if (type != KING && type != QUEEN && type != ROOK && type != KNIGHT &&
		type != BISHOP && type != PAWN && type != EMPTY_SQUARE)
	{
		throw GameException("Piece type is wrong!");
	}
	_type = type;
}

void Piece::setPosition(const Square& pos)
{
	if (!Square::checkSquare(pos.getX(), pos.getY()))
	{
		throw GameException("Position is illegal!");
	}
	_pos = pos;
}
