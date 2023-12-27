#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(const Square& pos)
	:Piece(EMPTY_SQUARE, EMPTY_SQUARE, pos)
{
}

EmptyPiece::~EmptyPiece()
{
}

std::vector<Square> EmptyPiece::findNewPossibleMoves(const Board& chessBoard)
{
	this->_possibleMoves.clear();  //empty square doesn't have any possible moves
}

