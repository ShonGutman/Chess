#pragma once

#include "Piece.h"

class Bishop : virtual public Piece
{
public:
	Bishop(char color, const Square& pos);
	virtual ~Bishop();
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};