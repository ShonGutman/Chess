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
	std::vector<Square> tempPM; //tempPosibleMoves
	Square step(_pos);

	if (_color == WHITE) //white pawn
	{
		if (_pos.getX() == 6) //first move can be two squares ahead
		{
			//x--
			step = _pos;
			if (step.DecX() && step.DecX() && chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
			{
				tempPM.push_back(step);
			}
		}

		//x-
		step = _pos;
		if (step.DecX() && chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
		{
			tempPM.push_back(step);
		}

		//x-y+
		step = _pos;
		if (step.DecX() && step.IncY() && chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color))
		{
			tempPM.push_back(step);
		}

		//x-y-
		step = _pos;
		if (step.DecX() && step.DecY() && chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color))
		{
			tempPM.push_back(step);
		}
	}
	else //black pawn
	{
		if (_pos.getX() == 1) //first move can be two squares ahead
		{
			//x++
			step = _pos;
			if (step.IncX() && step.IncX() && chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
			{
				tempPM.push_back(step);
			}
		}

		//x+
		step = _pos;
		if (step.IncX() && chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
		{
			tempPM.push_back(step);
		}

		//x+y+
		step = _pos;
		if (step.IncX() && step.IncY() && chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color))
		{
			tempPM.push_back(step);
		}

		//x+y-
		step = _pos;
		if (step.IncX() && step.DecY() && chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color))
		{
			tempPM.push_back(step);
		}
	}

	return tempPM;
}
