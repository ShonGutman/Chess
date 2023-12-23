#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(char color, Square& pos);
    virtual ~Knight();
    virtual void setPossibleMoves(const Board& chessBoard) override;
};