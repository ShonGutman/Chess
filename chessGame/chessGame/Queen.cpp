#include "Queen.h"

Queen::Queen(char color, const Square& pos)
	:Piece(color, QUEEN, pos)
{
}

Queen::~Queen()
{
}

std::vector<Square> Queen::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	//TODO LATER:
	return this->_possibleMoves;
}
