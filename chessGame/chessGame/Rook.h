#pragma once

#include "Piece.h"

class Rook : virtual public Piece
{
public:

	/*
	* constructor for Rook
	* @param color - color of chess Rook
	* @param pos - square of Rook
	*/
	Rook(char color, const Square& pos);

	/*
	* destructor for Rook
	*/
	virtual ~Rook();

	/*
	* get the possible moves after a move was done
	*
	* @param chessBoard - a chess board 2d array of piece*
	* @return vector of possible square moves
	*/
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};