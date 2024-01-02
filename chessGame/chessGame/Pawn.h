#pragma once

#include "Piece.h"

constexpr int BLACK_FIRST_RANK = 1;
constexpr int WHITE_FIRST_RANK = 6;

class Pawn : public Piece
{
public:

    /*
    * constructor for Pawn
    * @param color - color of chess Pawn
    * @param pos - square of Pawn
    */
    Pawn(char color, const Square& pos);

    /*
    * destructor for Pawn
    */
    virtual ~Pawn();

    /*
    * get the possible moves after a move was done
    *
    * @param chessBoard - a chess board 2d array of piece*
    * @return vector of possible square moves
    */
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;

    
};