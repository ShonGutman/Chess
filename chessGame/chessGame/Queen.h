#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(char color, const Square& pos);
    virtual ~Queen();
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};