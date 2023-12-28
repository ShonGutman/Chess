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
	std::vector<Square> tempPM; //tempPosibleMoves
	Square step(_pos);

	//x+
	while (step.IncX())
	{
		this->checkStep(step,tempPM,chessBoard);
	}

	//y+
	step = _pos;
	while (step.IncY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//x-
	step = _pos;
	while (step.DecX())
	{
		this->checkStep(step, tempPM, chessBoard);
	}

	//y-
	step = _pos;
	while (step.DecY())
	{
		this->checkStep(step, tempPM, chessBoard);
	}
	return tempPM;
}

void Rook::checkStep(Square& step, std::vector<Square>& possibleMoves, Piece* chessBoard[BOARD_SIZE][BOARD_SIZE])
{
	if (chessBoard[step.getX()][step.getY()]->getColor() == opColor(_color) ||
		chessBoard[step.getX()][step.getY()]->getColor() == EMPTY_SQUARE)
	{
		possibleMoves.push_back(step);
	}
}
