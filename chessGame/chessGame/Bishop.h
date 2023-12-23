#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(char color, Square& pos);
	virtual ~Bishop();
	virtual void setPossibleMoves(const Board& chessBoard) override;
};