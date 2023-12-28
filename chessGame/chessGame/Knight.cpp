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
	std::vector<Square> tempPM; //tempPosibleMoves
	Square step(_pos);

	//x++y+
	if (step.IncX() && step.IncX() && step.IncY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x++y-
	step = _pos;
	if (step.IncX() && step.IncX() && step.DecY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x--y+
	step = _pos;
	if (step.DecX() && step.DecX() && step.IncY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x--y-
	step = _pos;
	if (step.DecX() && step.DecX() && step.DecY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x+y++
	step = _pos;
	if (step.IncX() && step.IncY() && step.IncY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x-y++
	step = _pos;
	if (step.DecX() && step.IncY() && step.IncY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x+y--
	step = _pos;
	if (step.IncX() && step.DecY() && step.DecY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x-y--
	step = _pos;
	if (step.DecX() && step.DecY() && step.DecY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	return tempPM;
}
