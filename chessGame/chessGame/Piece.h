#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
#include "Board.h"
#include "GameException.h"

enum pieceColor
{
	BLACK = 'b',
	WHITE = 'W'
};

enum pieceType
{
	KING = 'K',
	QUEEN = 'Q',
	ROOK = 'R',
	KNIGHT = 'N',
	BISHOP = 'B',
	PAWN = 'P',
	EMPTY_SQUARE = '#'
};

class Board;

class Piece
{
public:
	/*
	* constructor for Piece
	* @param color - color of chess piece
	* @param type - piece type
	* @param pos - square of piece
	*/
	Piece(const char color, const char type, const Square& pos);

	/*
	* ctor of class Piece
	*/
	virtual ~Piece();

	void move(const Square& newPos);

	/*
	* return info about the piece
	*/
	char pieceInfo() const;

//getters:

	/*
	* getter of color
	* 
	* @return the color of the piece
	*/
	char getColor() const;

	/*
	* getter of type
	* 
	* @return type of the piece
	*/
	char getType() const;

	/*
	* getter of piece square
	* 
	* @return square of piece
	*/
	const Square& getPosition() const;

	/*
	* getter of possible moves
	* 
	* @return a vector with all posible squares
	*/
	std::vector<Square> getMoves() const;


	/*
	* clear all possible moves in piece
	* 
	* @return void
	*/
	void clearVector();
	
	/*
	* check if a move is in possible moves vector
	* 
	* @param moveTo - a square to check
	* @return true if can move. false if not
	*/
	bool isLegalMove(const Square& moveTo) const;

	static bool isLegalMove(const Square& moveTo, std::vector<Square> possibleMoves);

	virtual void setPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]);
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) = 0;

protected:
	char _color;
	char _type;
	Square _pos;
	std::vector<Square> _possibleMoves;


private:

//setters:

	/*
	* set the color of the piece
	*
	* @param color - color of chess piece
	*/
	void setColor(const char color);

	/*
	* set type of the piece
	* 
	* @param type - piece type
	*/
	void setType(const char type);

	/*
	* set square of the piece
	* 
	* @param pos - square of piece
	*/
	void setPosition(const Square& pos);
};