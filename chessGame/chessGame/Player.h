#pragma once

#include "Board.h"

class Player
{
public:
	Player(char color, Board& _chessBoard);
	~Player();
	Board& getBoard() const;
	int play(std::string move);

protected:
	bool _isMyTurn;
	char _color;
	Board _chessBoard;
};
