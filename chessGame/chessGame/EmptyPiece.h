#pragma once

#include "Piece.h"

class EmptyPiece : public Piece
{
public:
	EmptyPiece(Square& pos);
	virtual ~EmptyPiece();
	virtual void setPossibleMoves(const Board& chessBoard) override;
};
