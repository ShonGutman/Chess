#include "Game.h"

Game::Game(std::string filePath)
{
	_file.open(filePath, std::ofstream::out | std::ofstream::trunc);
	_chessBoard = new Board();
	_playerW = new Player(WHITE, _chessBoard);
	_playerB = new Player(BLACK, _chessBoard);
}

Game::~Game()
{
	_file << "Game ended" << std::endl;
	_file.close();

	delete this->_chessBoard;
	this->_chessBoard = nullptr; //avoid leaking memory

	delete this->_playerW;
	delete this->_playerB;

	//avoid leaking memory
	this->_playerW = nullptr;
	this->_playerB = nullptr;
}

int Game::play(std::string move)
{
	int code = 0;

	if(_playerW->getTurn())
	{
		code = _playerW->play(move);
	}
	else if(_playerB->getTurn())
	{
		code = _playerB->play(move);
	}
	else
	{
		throw GameException("It's no ones turn, how did we get here?!");
	}

	if(code == VALID_MOVE || code == VALID_CHECK_MOVE || code == CHECK_MATE)
	{
		if (_playerW->getTurn())
		{
			//write move into file:
			_file << "White played: ";
		}

		else
		{
			//write move into file:
			_file << "Black Played: ";
		}
		//write move into file:
		_file << move << std::endl;

		//swap the turn between black and white
		_playerB->setTurn();
		_playerW->setTurn();

	}
	return code;
}

void Game::printGameBoard() const
{
	_chessBoard->printBoard();
}

Piece* Game::getPiece(Square& squ) const
{
	return _chessBoard->getPiece(squ);
}

