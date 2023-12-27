#pragma once


#include "Player.h"

class Game
{
public:
	/*
	* constructor for Game
	*/
	Game();

	/*
	* destructor for Game. frees memory allocated for Game.
	*/
	~Game();

	/*
	* function gets a move to preform and does it, while returning an code to represent the state
	* 
	* @param move - string of requested move action
	* @return 0 - valid move
	* @return 1 - valid move (made opposing king in check)
	* @return 2 - invalid move (no piece of mine in PieceLocation)
	* @return 3 - invalid move (there is piece of mine in locationToMove)
	* @return 4 - invalid move (checking my king)
	* @return 5 - invalid move (square index are invalid)
	* @return 6 - invalid move (piece can't move like that)
	* @return 7 - invalid move (PieceLocation = locationToMove)
	* @return 8 - valid move (checkmate)
	*/
	int play(std::string move);

private:
	Player* _playerW;
	Player* _playerB;
	Board* _chessBoard;
};