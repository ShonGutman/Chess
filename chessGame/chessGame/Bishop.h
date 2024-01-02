#pragma once

#include "Piece.h"

class Bishop : virtual public Piece
{
public:

	/*
	* constructor for Bishop
	* @param color - color of chess Bishop
	* @param pos - square of Bishop
	*/
	Bishop(char color, const Square& pos);

	/*
	* destructor for Bishop
	*/
	virtual ~Bishop();

	/*
	* get the possible moves after a move was done
	*
	* @param chessBoard - a chess board 2d array of piece*
	* @return vector of possible square moves
	*/
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};