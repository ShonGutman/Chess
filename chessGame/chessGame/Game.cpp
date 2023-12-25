#include "Game.h"

Game::Game()
{
	Board* chessBoard = new Board;
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
