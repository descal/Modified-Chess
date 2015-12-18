#include "apolo.h"
#include<stdlib.h>

Apolo::Apolo(bool isWhite) : Piece(isWhite)
{
}

Apolo::~Apolo()
{
}

int Apolo::value() const
{
    return 3;
}

bool Apolo::checkMove(Square& location) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();

    // valid move if moving 2 square forward/backwards
    // and 2 squares sideways
    if(abs(translationY) == 2 && abs(translationX) == 2)
    {
        validMove = true;
    }

    return validMove;


}


void Apolo::display() const
{
    cout <<_color+"A";
}
string Apolo::displayName()const{
      string name;
            name=_color+"A";


    return name;
}

