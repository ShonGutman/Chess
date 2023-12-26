#include "EmptyPiece.h"

EmptyPiece::EmptyPiece(Square& pos)
	:Piece(EMPTY_SQUARE, EMPTY_SQUARE, pos)
{
}

EmptyPiece::~EmptyPiece()
{
}

void EmptyPiece::setPossibleMoves(const Board& chessBoard)
{
	this->_possibleMoves.clear();  //empty square doesn't have any possible moves
}
