#include "PieceException.h"


PieceException::PieceException(const std::string error)
{
    this->_errorMsg = error;
}

PieceException::~PieceException()
{
    this->_errorMsg.clear();
}

const char* PieceException::what() const
{
    return this->_errorMsg.c_str();
}
