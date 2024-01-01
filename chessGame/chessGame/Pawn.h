#pragma once

#include "Piece.h"

constexpr int BLACK_FIRST_RANK = 1;
constexpr int WHITE_FIRST_RANK = 6;

class Pawn : public Piece
{
public:
    Pawn(char color, const Square& pos);
    virtual ~Pawn();
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;

    
};