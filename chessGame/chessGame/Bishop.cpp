#include "Bishop.h"

Bishop::Bishop(char color, const Square& pos)
	:Piece(color, BISHOP, pos)
{

}

Bishop::~Bishop()
{
}

std::vector<Square> Bishop::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	//TODO LATER:
	return this->_possibleMoves;
}
