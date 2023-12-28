#include "Bishop.h"

Bishop::Bishop(char color, const Square& pos)
	:Piece(color, BISHOP, pos)
{

}

Bishop::~Bishop()
{
}

std::vector<Square> Bishop::findNewPossibleMoves(Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	std::vector<Square> tempPM; //tempPosibleMoves
	Square step(_pos);

	//x+y+
	while (step.IncX() && step.IncY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x+y-
	step = _pos;
	while (step.IncX() && step.DecY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x-y+
	step = _pos;
	while (step.DecX() && step.IncY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	//x-y-
	step = _pos;
	while (step.DecX() && step.DecY() && this->checkStep(step, tempPM, chessBoard))
	{
	}

	return tempPM;
}
