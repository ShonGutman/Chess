#pragma once

#include "Player.h"

class Game : public Player
{
public:
	Game();
	~Game();
	int play(std::string move);

private:
	Player _playerW;
	Player _playerB;
};