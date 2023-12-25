#pragma once


#include <iostream>
#include "Square.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"

constexpr int INVALID_SQUARE = 5;

class Piece;

class Board
{
public:
	//constructors
	/*
	* constructor for Board
	*/
	Board();

	//destructor
	/*
	* destructor for Board. frees memory allocated for Board.
	*/
	~Board();

	void setBoard();

	/*
	* move a piece to another Square
	* 
	* @param squFrom - Square of piece to move
	* @param squTo - Square to move the piece to
	* @param myColor - the color of the player
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
	int move(const Square& squFrom, const Square& squTo, const char myColor);


private:
	Piece* _chessBoard[BOARD_SIZE][BOARD_SIZE];


	//helping methods:

	/*
	* check if squ is an empty square
	*
	* @param squ - a square to be checked
	* @return true if empty. false if not
	*/
	bool isEmptySquare(const Square& squ) const;

	/*
	* find the square of a specific king
	*
	* @param kingColor - the color of the wanted king
	* @return the king's square
	*/
	Square findKing(const char kingColor) const;

	/*
	* check if a certain piece is checking certain king
	*
	* @param piece - a piece to be checked
	* @param kingColor - the color of the king
	* @return true if check. false if not
	*/
	bool isPieceCheckKing(const Piece& piece, const char kingColor) const;
};
