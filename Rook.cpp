#include "rook.h"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
}

Rook::~Rook()
{
}

int Rook::value() const
{
    return 5;
}

bool Rook::checkMove(Square& location) const
{
    bool validMove = false;

    // valid move if moving on a clear vertical
    if(Board::getBoard()->isClearVertical(*(this->location()), location))
    {
        validMove = true;
    }

    // valid move if moving on a clear horizontal
    else if(Board::getBoard()->isClearHorizontal(*(this->location()), location))
    {
        validMove = true;
    }

    return validMove;
}


void Rook::display() const
{
    cout << _color + "R";
}

string Rook::displayName()const{
      string name;
            name=_color+"R";


    return name;
}
