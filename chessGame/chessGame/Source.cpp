/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Game.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
	/*srand(time_t(NULL));
	try
	{
		Game chessGame;
		cout << "Starting new game!" << endl;
		string move;
		while (1)
		{
			chessGame.printGameBoard();
			cout << "Enter Move string: ";
			cin >> move;
			cout << "Move return code:" << chessGame.play(move) << endl;
		}

	}
	catch (GameException& e)
	{
		std::cerr << "Error: " << e.what() << endl;
		return -1;
	}
	catch (...)
	{
		std::cerr << "Error: It's ok, I don't understand chess or what you've done" << endl;
		return -1;
	}*/

	Pipe p;
	bool isConnect = p.connect();
	Game chessGame;
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;
		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return -1;
		}
	}
	
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	strcpy_s(msgToGraphics, "rnbqkbnr"
							"pppppppp"
							"########"
							"########"
							"########"
							"########"
							"PPPPPPPP"
							"RNBQKBNR0"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		
		/******* JUST FOR EREZ DEBUGGING ******/
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/

		while (msgFromGraphics.length() == SQUARE_STRING_LENGTH)
		{
			Square clickedSqu;
			Square::getSqu(msgFromGraphics, clickedSqu);
			string moves = "";
			moves = chessGame.Game::getPiece(clickedSqu)->movesToString();

			strcpy_s(msgToGraphics, moves.c_str());
			p.sendMessageToGraphics(msgToGraphics);

			msgFromGraphics = p.getMessageFromGraphics();
		}
		const char code[2] = { char('0' + chessGame.play(msgFromGraphics)) };
		strcpy_s(msgToGraphics, code); // msgToGraphics should contain the result of the operation
		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   
		// get message from graphics
		if (code[0] == char('0' + CHECK_MATE))
		{
			break; //game has ended
		}
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
	return 0;
}