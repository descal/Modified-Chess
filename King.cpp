#include "king.h"
#include<stdlib.h>

King::King(bool isWhite) : Piece(isWhite)
{
}

King::~King()
{
}

int King::value() const
{
    return 0;
}

bool King::checkMove(Square& location) const
{
    bool validMove = false;
    int translationX = location.getX() - this->location()->getX();
    int translationY = location.getY() - this->location()->getY();

    // valid move if moving 1 square forward/backwards
    if(abs(translationY) == 1 && translationX == 0)
    {
        validMove = true;
    }

    // valid move if moving 1 square sideways
    else if(abs(translationX) == 1 && translationY == 0)
    {
        validMove = true;
    }

    // valid move if moving 1 square diagonally
    else if(abs(translationX) == 1 && abs(translationY) == 1)
    {
        validMove = true;
    }

    return validMove;
}


void King::display() const
{
    cout << _color + "K";
}

string King::displayName()const{
      string name;
            name=_color+"K";


    return name;
}
