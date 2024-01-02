#pragma once

#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop
{
public:

    /*
    * constructor for Queen
    * @param color - color of chess Queen
    * @param pos - square of Queen
    */
    Queen(char color, const Square& pos);

    /*
    * destructor for Queen
    */
    virtual ~Queen();

    /*
    * get the possible moves after a move was done
    *
    * @param chessBoard - a chess board 2d array of piece*
    * @return vector of possible square moves
    */
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};