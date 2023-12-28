#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(char color, const Square& pos);
	virtual ~Rook();
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;

private:
	void checkStep(Square& step, std::vector<Square>& possibleMoves, Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]);
};