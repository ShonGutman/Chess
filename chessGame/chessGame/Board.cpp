#include "Board.h"

Board::Board()
{
	this->setBoard();
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			//delete allocated memory
			delete this->_chessBoard[i][j];
			//avoid leaking memory
			this->_chessBoard[i][j] = nullptr;
		}
	}
}

bool Board::isPieceCheckKing(const Piece& piece, const char kingColor) const
{
	Square kingSquare = findKing(kingColor);
	return piece.isLegalMove(kingSquare);
}

bool Board::isEmptySquare(const Square& squ) const
{
	return this->_chessBoard[squ.getX()][squ.getY()]->getType() == EMPTY_SQUARE;
}

Square Board::findKing(const char kingColor) const
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->_chessBoard[i][j]->getColor() == kingColor &&
				this->_chessBoard[i][j]->getType() == KING)
			{
				return this->_chessBoard[i][j]->getPosition();
			}
		}
	}

	throw GameException("King was not found. maybe king doesn't exist.");
}
