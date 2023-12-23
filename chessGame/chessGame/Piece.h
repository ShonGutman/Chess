#pragma once

#include <iostream>
#include <vector>
#include "Square.h"
#include "Board.h"
#include "PieceException.h"

#define BLACK 'b'
#define WHITE 'W'

#define KING 'k'
#define QUEEN 'q'
#define ROOK 'r'
#define KNIGHT 'n'
#define BISHOP 'b'
#define PAWN 'p'

#define EMPTY_SQUARE '#'

class Board;

class Piece
{
public:
	Piece(const char color, const char type, const Square& pos);

	virtual ~Piece();

	void move(const Square& newPos);

	std::string pieceInfo() const;

	char getColor() const;
	char getType() const;
	Square& getPosition() const;
	std::vector<Square> getMoves() const;

	void clearVector();
	
	bool isLegalMove(const Square& moveTo) const;

	virtual void setPossibleMoves(const Board& chessBoard) = 0;

protected:
	char _color;
	char _type;
	Square _position;
	std::vector<Square> _possibleMoves;
};