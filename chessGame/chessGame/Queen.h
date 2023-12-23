#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(char color, Square& pos);
    virtual ~Queen();
    virtual void setPossibleMoves(const Board& chessBoard) override;
};