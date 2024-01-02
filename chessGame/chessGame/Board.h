#pragma once


#include <iostream>
#include "Square.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "EmptyPiece.h"


enum CODES {
	VALID_MOVE = 0,
	VALID_CHECK_MOVE,
	NO_PIECE_FROM, 
	EXIST_PIECE_TO,
	PERSONAL_CHECK, 
	OUT_OF_BOARD, 
	ILLIGAL_MOVE, 
	SAME_SQUARE,
	CHECK_MATE
};

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

	/*
	* function will set a board acording to a given string to set pieces
	* 
	* @param initGame - a string that represents all pieces squares'
	*/
	void setBoard(const std::string initGame);

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

	/*
	* print the board for the user
	*/
	void printBoard() const;

	/*
	* get piece at given square
	* @param squ - square of wanted piece
	* @returns wanted piece
	*/
	Piece* getPiece(Square& squ) const;

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
	* @param possibleMoves - vector of possoble moves that piece can go to
	* @param kingColor - the color of the king
	* @return true if check. false if not
	*/
	bool isPieceCheckKing(const std::vector<Square> possibleMoves, const char kingColor) const;

	/*
	* function sets the possible moves vector to all pieces in board
	*/
	void setAllMoves();

	/*
	* function will check if a certain king is in check
	* 
	* @param kingColor - the color of the requested king
	*/
	bool isInCheck(const char kingColor) const;
};
