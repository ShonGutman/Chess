#pragma once

#include "Piece.h"

class EmptyPiece : public Piece
{
public:
	EmptyPiece(const Square& pos);
	virtual ~EmptyPiece();
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};
