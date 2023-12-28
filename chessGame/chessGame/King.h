#pragma once

#include "Piece.h"

class King : public Piece
{
public:
	King(char color, const Square& pos);
	virtual ~King();
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
private:
	void checkStep(Square& step, std::vector<Square>& possibleMoves, Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]);
};