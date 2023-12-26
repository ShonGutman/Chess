#include "GameException.h"


GameException::GameException(const std::string error)
{
    this->_errorMsg = error;
}

GameException::~GameException()
{
    this->_errorMsg.clear();
}

const char* GameException::what() const
{
    return this->_errorMsg.c_str();
}
