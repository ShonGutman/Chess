#include "King.h"

King::King(char color, const Square& pos)
	:Piece(color, KING , pos)
{
}

King::~King()
{
}

std::vector<Square> King::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	std::vector<Square> tempPM; //tempPosibleMoves
	Square step(_pos);

	//x+
	step.IncX();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//x-
	step = _pos;
	step.DecX();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//y+
	step = _pos;
	step.IncY();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//y-
	step = _pos;
	step.DecY();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//x+y+
	step = _pos;
	step.IncX();
	step.IncY();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//x+y-
	step = _pos;
	step.IncX();
	step.DecY();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//x-y+
	step = _pos;
	step.DecX();
	step.IncY();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	//x-y-
	step = _pos;
	step.DecX();
	step.DecX();
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		tempPM.push_back(step);
	}

	return tempPM;
}
