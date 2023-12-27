#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(const Square& pos)
	:Piece(EMPTY_SQUARE, EMPTY_SQUARE, pos)
{
}

EmptyPiece::~EmptyPiece()
{
}

std::vector<Square> EmptyPiece::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	this->_possibleMoves.clear();  //empty square doesn't have any possible moves
	return this->_possibleMoves;
}

