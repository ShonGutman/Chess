#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Square.h"
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

	/*
	* function moves piece to a given square
	* 
	* @param newPos - square to go to
	*/
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
	* return oposite color of a given color
	* 
	* @param color - color of a piece
	* @return the oposite color
	*/
	static char opColor(const char color);

	/*
	* check if a move is in possible moves vector
	* 
	* @param moveTo - a square to check
	* @return true if can move. false if not
	*/
	bool isLegalMove(const Square& moveTo) const;

	/*
	* check if a move is in possible moves vector
	*
	* @param moveTo - a square to check
	* @param possibleMoves - vector of possible moves
	* @return true if can move. false if not
	*/
	static bool isLegalMove(const Square& moveTo, std::vector<Square> possibleMoves);

	/*
	* set vector of possible move
	* 
	* @param chessBoard - a chess board 2d array of piece* 
	*/
	void setPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]);

	/*
	* get the possible moves after a move was done
	* 
	* @param chessBoard - a chess board 2d array of piece* 
	* @return vector of possible square moves
	*/
	virtual std::vector<Square> findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]) = 0;

protected:
	char _color;
	char _type;
	Square _pos;
	std::vector<Square> _possibleMoves;
	bool checkStep(Square& step, std::vector<Square>& possibleMoves, Piece* chessBoard[BOARD_SIZE][BOARD_SIZE]);


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