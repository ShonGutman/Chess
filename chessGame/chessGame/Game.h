#pragma once


#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	int play(std::string move);

private:
	Player _playerW;
	Player _playerB;
	Board* _chessBoard;
};