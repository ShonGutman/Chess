#pragma once

#include <exception>
#include <iostream>
#include <string>

class GameException : public std::exception
{
public:
	/*
	* CTOR of class GameException
	* 
	* @param error - an error msg
	*/
	GameException(const std::string error);

	/*
	* DTOR of class GameException
	*/
	~GameException();

	/*
	* override of func what() in Exception
	*/
	virtual const char* what() const override;

private:
	std::string _errorMsg;
};
