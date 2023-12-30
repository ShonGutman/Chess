#pragma once

#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop
{
public:
    Queen(char color, const Square& pos);
    virtual ~Queen();
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};