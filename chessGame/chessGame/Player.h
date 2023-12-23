#pragma once

#include "Board.h"

class Player
{
public:
	Player(char color);
	~Player();
	int Play(std::string move);

private:
	bool _isMyTurn;
	char _color;
	Board _chessBoard;
};
