#pragma once

#include <exception>

class PieceException : public std::exception
{
public:

	virtual const char* what() const override;
};
