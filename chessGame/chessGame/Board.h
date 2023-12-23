#pragma once


#include <iostream>
#include "Square.h"
#include "Piece.h"

constexpr int BOARD_SIZE = 8;

class Piece;

class Board
{
public:

	Board();
	~Board();

	void move(const Square& PieceLocation, const Square& locationToMove);
	bool isEmptySquare(const Square& checkSquare) const;

	Square& findKingSquare(const char kingColor) const;
	bool isCheckingKing(const Square& checkingPieceLocation, const Square& kingLocation) const;

private:
	Piece* _chessBoard[BOARD_SIZE][BOARD_SIZE];
};
