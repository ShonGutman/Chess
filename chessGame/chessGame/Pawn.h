#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
    Pawn(char color, Square& pos);
    virtual ~Pawn();
    virtual void setPossibleMoves(const Board& chessBoard) override;
};