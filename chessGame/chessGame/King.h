#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King(char color, Square& pos);
	virtual ~King();
	virtual void setPossibleMoves(const Board& chessBoard) override;
};