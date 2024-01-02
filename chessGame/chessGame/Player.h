#pragma once

#include "Board.h"
#include <ctype.h>

class Player
{
public:

	/*
	* constructor for Player
	* @param color - color of chess Bishop
	* @param pos - square of Bishop
	*/
	Player();

	/*
	* constructor for Player
	* @param color - color of chess player
	* @param chessBoard - common refernce of same board between players
	*/
	Player(const char color, Board* chessBoard);

	/*
	* destructor for Player
	*/
	~Player();

	/*
	* getter of chess board
	*/
	Board& getBoard() const;

	/*
	* getter of isMyTurn
	*/
	bool getTurn() const;

	/*
	* setter of turn
	*/
	void setTurn();

	/*
	* move a piece to another Square
	*
	* @param squFrom - Square of piece to move
	* @param squTo - Square to move the piece to
	* @param myColor - the color of the player
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
	int play(std::string& move);

private:
	char _color;
	bool _isMyTurn;
	Board* _chessBoard;
};
