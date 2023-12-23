#include "Game.h"

Game::Game()
{
	Board chessBoard;
	Player playerW(WHITE,chessBoard);
	Player playerB(BLACK,chessBoard);
}

Game::~Game()
{
}

int Game::play(std::string move)
{
	return 0;
}
