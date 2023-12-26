#pragma once

#include "Board.h"
#include <ctype.h>

constexpr int MOVE_STRING_LENGTH = 4;

class Player
{
public:
	Player();
	Player(const char color, Board* chessBoard);
	~Player();
	Board& getBoard() const;
	bool getTurn() const;
	void setTurn();
	int play(std::string move);

private:
	char _color;
	bool _isMyTurn;
	Board* _chessBoard;
};
