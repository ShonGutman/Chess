#include "PieceException.h"

const char* PieceException::what() const
{
    return "Error with Piece";
}
