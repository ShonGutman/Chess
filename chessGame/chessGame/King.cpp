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
	if (step.IncX())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//x-
	step = _pos;
	if (step.DecX())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//y+
	step = _pos;
	if (step.IncY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//y-
	step = _pos;
	if (step.DecY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//x+y+
	step = _pos;
	if (step.IncX() && step.IncY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}



	//x+y-
	step = _pos;
	if (step.IncX() && step.DecY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//x-y+
	step = _pos;
	if (step.DecX() && step.IncY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//x-y-
	step = _pos;
	if (step.DecX() && step.DecX())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	return tempPM;
}

void King::checkStep(Square& step, std::vector<Square>& possibleMoves, Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		possibleMoves.push_back(step);
	}
}
