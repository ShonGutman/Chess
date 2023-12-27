#include "Pawn.h"

Pawn::Pawn(char color, const Square& pos)
	:Piece(color, PAWN, pos)
{
}

Pawn::~Pawn()
{
}

std::vector<Square> Pawn::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	//TODO LATER:
	return this->_possibleMoves;
}
