#include "Game.h"

Game::Game()
{
	_chessBoard = new Board();
	_playerW = Player(WHITE, _chessBoard);
	_playerB = Player(BLACK, _chessBoard);
}

Game::~Game()
{
	delete this->_chessBoard;
	this->_chessBoard = nullptr; //avoid leaking memory
}

int Game::play(std::string move)
{
	int code = 0;

	if(_playerW.getTurn())
	{
		code = _playerW.play(move);
	}
	else if(_playerB.getTurn())
	{
		int code = _playerB.play(move);
	}
	else
	{
		throw GameException("It's no ones turn, how did we get here?!");
	}

	if(code == VALID_MOVE || code == VALID_CHECK_MOVE || code == CHECK_MATE)
	{
		//swap the turn between black and white
		_playerB.setTurn();
		_playerW.setTurn();
	}
	return code;
}
