#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:

    /*
    * constructor for Knight
    * @param color - color of chess Knight
    * @param pos - square of Knight
    */
    Knight(char color, const Square& pos);

    /*
    * destructor for Knight
    */
    virtual ~Knight();

    /*
    * get the possible moves after a move was done
    *
    * @param chessBoard - a chess board 2d array of piece*
    * @return vector of possible square moves
    */
    virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};