#include "Board.h"

Board::Board()
{
	this->setBoard("pppppppp"
				   "rnbkqbnr"
				   "########"
				   "########"
				   "########"
				   "########"
				   "RNBKQBNR"
				   "PPPPPPPP");
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

void Board::setBoard(const std::string initGame)
{
	if(initGame.length() != BOARD_SIZE * BOARD_SIZE)
	{
		throw GameException("Can't create board with less then 64 pieces!");
	}
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Square tempSqu(i, j);
			
			if (initGame[i * BOARD_SIZE + j] == tolower(PAWN)) // black pawn
			{
				this->_chessBoard[i][j] = new Pawn(BLACK, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == PAWN) // white pawn
			{
				this->_chessBoard[i][j] = new Pawn(WHITE, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == tolower(ROOK)) // black rook
			{
				this->_chessBoard[i][j] = new Rook(BLACK, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == ROOK) // white rook
			{
				this->_chessBoard[i][j] = new Rook(WHITE, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == tolower(BISHOP)) // black bishop
			{
				this->_chessBoard[i][j] = new Bishop(BLACK, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == BISHOP) // white bishop
			{
				this->_chessBoard[i][j] = new Bishop(WHITE, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == tolower(KNIGHT)) // black knight
			{
				this->_chessBoard[i][j] = new Knight(BLACK, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == KNIGHT) // white knight
			{
				this->_chessBoard[i][j] = new Knight(WHITE, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == tolower(QUEEN)) // black queen
			{
				this->_chessBoard[i][j] = new Queen(BLACK, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == QUEEN) // white queen
			{
				this->_chessBoard[i][j] = new Queen(WHITE, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == tolower(KING)) // black king
			{
				this->_chessBoard[i][j] = new King(BLACK, tempSqu);
			}

			else if (initGame[i * BOARD_SIZE + j] == KING) // white king
			{
				this->_chessBoard[i][j] = new King(WHITE, tempSqu);
			}

			else //empty square
			{
				this->_chessBoard[i][j] = new EmptyPiece(tempSqu);
			}
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
