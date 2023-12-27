#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(char color, const Square& pos);
    virtual ~Pawn();
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};