#include "Queen.h"

Queen::Queen(char color, const Square& pos)
	:Piece(color, QUEEN, pos), Rook(color, pos), Bishop(color, pos)
{
}

Queen::~Queen()
{
}

std::vector<Square> Queen::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	std::vector<Square> rookMoves = Rook::findNewPossibleMoves(chessBoard);
	std::vector<Square> bishopMoves = Bishop::findNewPossibleMoves(chessBoard);

	rookMoves.insert(rookMoves.end(), bishopMoves.begin(), bishopMoves.end());
	return rookMoves;
}
