#pragma once

#include <exception>
#include <iostream>
#include <string>

class PieceException : public std::exception
{
public:
	/*
	* CTOR of class PieceException
	* 
	* @param error - an error msg
	*/
	PieceException(const std::string error);

	/*
	* DTOR of class PieceException
	*/
	~PieceException();

	/*
	* override of func what() in Exception
	*/
	virtual const char* what() const override;

private:
	std::string _errorMsg
};
