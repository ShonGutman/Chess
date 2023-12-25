#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
#include "Board.h"
#include "PieceException.h"

#define BLACK 'b'
#define WHITE 'W'

#define KING 'K'
#define QUEEN 'Q'
#define ROOK 'R'
#define KNIGHT 'N'
#define BISHOP 'B'
#define PAWN 'P'

#define EMPTY_SQUARE '#'

constexpr int BOARD_SIZE = 8;

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

	virtual void setPossibleMoves(const Board& chessBoard) = 0;

protected:
	char _color;
	char _type;
	Square _position;
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