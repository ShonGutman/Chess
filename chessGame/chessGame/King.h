#pragma once

#include "Piece.h"

class King : public Piece
{
public:

	/*
	* constructor for King
	* @param color - color of chess King
	* @param pos - square of King
	*/
	King(char color, const Square& pos);

	/*
	* destructor for King
	*/
	virtual ~King();

	/*
	* get the possible moves after a move was done
	*
	* @param chessBoard - a chess board 2d array of piece*
	* @return vector of possible square moves
	*/
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};