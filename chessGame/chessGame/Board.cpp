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

bool Board::isPieceCheckKing(const std::vector<Square> possibleMoves, const char kingColor) const
{
	Square kingSquare = findKing(kingColor);
	return Piece::isLegalMove(kingSquare, possibleMoves);
}

int Board::move(const Square& squFrom, const Square& squTo, const char myColor)
{
	Piece* fromTemp = this->_chessBoard[squFrom.getX()][squFrom.getY()];
	Piece* toTemp = this->_chessBoard[squTo.getX()][squTo.getY()];

	//check if target and dest square are the same
	if (squFrom == squTo)
	{
		return SAME_SQUARE;
	}

	if (fromTemp->getColor() != myColor)
	{
		return NO_PIECE_FROM;
	}

	if (toTemp->getColor() != myColor)
	{
		return EXIST_PIECE_TO;
	}

	if (!fromTemp->isLegalMove(squTo))
	{
		return ILLIGAL_MOVE;
	}

	std::vector<Square> tempPossibleMoves;

	fromTemp->move(squTo);
	this->_chessBoard[squFrom.getX()][squFrom.getY()] = new EmptyPiece(squFrom);
	this->_chessBoard[squTo.getX()][squTo.getY()] = fromTemp;

	char opColor = ' ';
	if (myColor == WHITE)
	{
		opColor = BLACK;
	}

	else if(myColor == BLACK)
	{
		opColor = WHITE;
	}

	//check if move check my king
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			
			if (this->_chessBoard[i][j]->getColor() == opColor)
			{
				tempPossibleMoves = this->_chessBoard[i][j]->findNewPossibleMoves(this->_chessBoard);

				//find out if opponent king is checking my own king after this move
				if (this->isPieceCheckKing(tempPossibleMoves, myColor))
				{
					//revert the move.
					fromTemp->move(squFrom);
					delete this->_chessBoard[squFrom.getX()][squFrom.getY()];
					this->_chessBoard[squFrom.getX()][squFrom.getY()] = fromTemp;
					this->_chessBoard[squTo.getX()][squTo.getY()] = toTemp;
					return PERSONAL_CHECK;
				}
			}
		}
	}

	this->setAllMoves();

	//check if move check oponent king
	if (this->isInCheck(opColor))
	{
		return VALID_CHECK_MOVE;
	}

	return VALID_MOVE;
}

void Board::setAllMoves()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->_chessBoard[i][j]->setPossibleMoves(this->_chessBoard);
		}
	}
}

bool Board::isInCheck(const char kingColor) const
{
	//oposite piece color
	char opColor = ' ';
	if (kingColor == WHITE)
	{
		opColor = BLACK;
	}

	else if (kingColor == BLACK)
	{
		opColor = WHITE;
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->_chessBoard[i][j]->getColor() == opColor)
			{
				if (this->isPieceCheckKing(this->_chessBoard[i][j]->getMoves(), kingColor))
				{
					return true;
				}
			}
		}
	}
	return false;
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
