#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(char color, Square& pos);
	virtual ~Rook();
	virtual void setPossibleMoves(const Board& chessBoard) override;
};