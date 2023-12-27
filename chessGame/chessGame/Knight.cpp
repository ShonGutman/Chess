#include "Knight.h"

Knight::Knight(char color, const Square& pos)
	:Piece(color, KNIGHT, pos)
{
}

Knight::~Knight()
{
}

std::vector<Square> Knight::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	//TODO LATER:
	return this->_possibleMoves;
}
