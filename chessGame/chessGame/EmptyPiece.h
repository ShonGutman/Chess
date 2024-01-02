#pragma once

#include "Piece.h"

class EmptyPiece : public Piece
{
public:
	/*
	* constructor for EmptyPiece
	* @param pos - square of EmptyPiece
	*/
	EmptyPiece(const Square& pos);

	/*
	* destructor for EmptyPiece
	*/
	virtual ~EmptyPiece();

	/*
	* get the possible moves after a move was done
	*
	* @param chessBoard - a chess board 2d array of piece*
	* @return vector of possible square moves
	*/
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) override;
};
