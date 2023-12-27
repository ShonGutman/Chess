#include "Rook.h"

Rook::Rook(char color, const Square& pos)
    :Piece(color, ROOK, pos)
{
}

Rook::~Rook()
{
}

std::vector<Square> Rook::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	std::vector<Square> tempPM; //temoPosibleMoves
	Square step(_pos);

	//x+
	while (step.getX() < BOARD_SIZE)
	{
		step.IncX();
		if (chessBoard[step.getX()][step.getY()]->getColor() == Piece::opColor(_color))
		{
			tempPM.push_back(step);
			break;
		}
		if (chessBoard[step.getX()][step.getY()]->getColor() != EMPTY_SQUARE)
		{
			break;
		}
		tempPM.push_back(step);
	}

	//y+
	step = _pos;
	while (step.getX() < BOARD_SIZE)
	{
		step.IncY();
		if (chessBoard[step.getX()][step.getY()]->getColor() == Piece::opColor(_color))
		{
			tempPM.push_back(step);
			break;
		}
		if (chessBoard[step.getX()][step.getY()]->getType() != EMPTY_SQUARE)
		{
			break;
		}
		tempPM.push_back(step);
	}

	//x-
	step = _pos;
	while (step.getX() == 0)
	{
		step.DecX();
		if (chessBoard[step.getX()][step.getY()]->getColor() == Piece::opColor(_color))
		{
			tempPM.push_back(step);
			break;
		}
		if (chessBoard[step.getX()][step.getY()]->getType() != EMPTY_SQUARE)
		{
			break;
		}
		tempPM.push_back(step);
	}

	//y-
	step = _pos;
	while (step.getX() == 0)
	{
		step.DecY();
		if (chessBoard[step.getX()][step.getY()]->getColor() == Piece::opColor(_color))
		{
			tempPM.push_back(step);
			break;
		}
		if (chessBoard[step.getX()][step.getY()]->getType() != EMPTY_SQUARE)
		{
			break;
		}
		tempPM.push_back(step);
	}
	return tempPM;
}