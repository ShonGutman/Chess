#pragma once

#include <iostream>
#include <vector>
#include "Square.h"
#include "Board.h"

class Board;

class Piece
{

public:
	Piece(const char color, const char type, const Square& position);

	virtual ~Piece();

	void move(const Square& newPosition);

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