#pragma once

#include "Board.h"

class Player
{
public:
	Player(const char color, Board* chessBoard);
	~Player();
	Board& getBoard() const;
	int play(std::string move);

protected:
	char _color;
	bool _isMyTurn;
	Board* _chessBoard;
};
