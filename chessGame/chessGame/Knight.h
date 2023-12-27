#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(char color, const Square& pos);
    virtual ~Knight();
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};