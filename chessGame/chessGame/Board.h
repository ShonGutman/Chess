#pragma once


#include <iostream>
#include "Square.h"
#include "Piece.h"

constexpr int BOARD_SIZE = 8;

class Piece;

class Board
{
public:
	/*
	* CTOR of class Board
	*/
	Board();

	/*
	* DTOR of class Board
	*/
	~Board();

	/*
	* move a piece to another Square
	* 
	* @param PieceLocation - Square of piece to move
	* @param locationToMove - Square to move the piece to 
	* @return 0 - valid move
	* @return 1 - valid move (made opposing king in check)
	* @return 2 - invalid move (no piece of mine in PieceLocation)
	* @return 3 - invalid move (there is piece of mine in locationToMove)
	* @return 4 - invalid move (checking my king)
	* @return 5 - invalid move (square index are invalid)
	* @return 6 - invalid move (piece can't move like that)
	* @return 7 - invalid move (PieceLocation = locationToMove)
	* @return 8 - valid move (checkmate)
	*/
	int move(const Square& PieceLocation, const Square& locationToMove, const char myColor);
	bool isEmptySquare(const Square& checkSquare) const;

	void setBoard();

	Square& findKingSquare(const char kingColor) const;
	bool isCheckingKing(const Square& checkingPieceLocation, const Square& kingLocation) const;

private:
	Piece* _chessBoard[BOARD_SIZE][BOARD_SIZE];
};
