#pragma once

#include "Board.h"

class Player
{
protected:
	Player(char color, Board& _chessBoard);
	~Player();
	Board& getBoard() const;
	int play(std::string move);

private:
	bool _isMyTurn;
	char _color;
	Board _chessBoard;
};
