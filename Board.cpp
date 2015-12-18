#include "board.h"
#include "piece.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Board::Board()
{
    // Set up squares (_DIMENSION x _DIMENSION)
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = 0; j < _DIMENSION; j++)
        {
            _squares[i][j] = new Square(i, j);
        }
    }
}

Board::~Board()
{
    // Delete squares
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = 0; j < _DIMENSION; j++)
        {
            delete[] _squares[i][j];
        }
        delete[] _squares[i];
    }
    delete[] _squares;
}

Board* Board::getBoard()
{
    if (!_theBoard)
        _theBoard = new Board();
    return _theBoard;
}

Square* Board::squareAt(int x, int y) const
{
    return _squares[x][y];
}

bool Board::isClearVertical(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;

    // determine which square has the smaller y-value,
    // (this helps to determine which direction to travel in)
    if(from.getY() <= to.getY())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    // check that there is no horizontal movement
    if(start->getX() != end->getX())
    {
        valid = false;
    }
    else
    {
        // iterate over vertical interval between squares
        for(int i = start->getY() + 1; i < end->getY(); i++)
        {
            // if a square is occupied, the vertical is not clear
            if(squareAt(start->getX(), i)->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool Board::isClearHorizontal(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;

    // determine which square has the smaller x-value,
    // (this helps to determine which direction to travel in)
    if(from.getX() <= to.getX())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    // check that there is no vertical movement
    if(start->getY() != end->getY())
    {
        valid = false;
    }
    else
    {
        // iterate over horizontal interval between squares
        for(int i = start->getX() + 1; i < end->getX(); i++)
        {
            // if a square is occupied, the vertical is not clear
            if(squareAt(i, start->getY())->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool Board::isClearDiagonal(Square& from, Square& to) const
{
    bool valid = true;
    int translationX = to.getX() - from.getX();
    int translationY = to.getY() - from.getY();
    int xDir = 1;
    int yDir = 1;

    if(translationX < 0)
    {
        xDir = -1;
    }

    if(translationY < 0)
    {
        yDir = -1;
    }

    // not a diagonal if absolute value of x and y translations don't match
    if(abs(translationX) != abs(translationY))
    {
        valid = false;
    }
    else
    {
        // iterate over diagonal interval between squares
        for(int i = 1; i < abs(translationX); i++)
        {
            // if a square is occupied, the diagonal is not clear
            if(squareAt(from.getX() + (i * xDir), from.getY() + (i * yDir))->occupied())
            {
                valid = false;
            }
        }
    }

    return valid;
}

bool Board::isEndRow(Square& location) const
{
    return (location.getY() == 0 || location.getY() == (_DIMENSION - 1));
}
/*
void Board::saveGame(){

    for (int y = _DIMENSION - 1; y >= 0; y--) // display black at top, white at bottom
    {
        cout << endl<< y + 1;
        for (int x = 0; x < _DIMENSION; x++)
        {


            static int pos=0;


            if(_squares[x][y]->occupied()){

                _save[pos]=_squares[x][y]->occupiedBy()->toSave();
                pos++;


            }



        }

    }





}
*/
void Board::displayBoard() const
{


    // display each square and any pieces on the board
    cout << endl <<"        A        B        C        D        E        F        G        H    " ;
    cout << endl <<"    #########################################################################";
    cout << endl <<"    #        #        #        #        #        #        #        #        #";





    for (int y = _DIMENSION - 1; y >= 0; y--) // display black at top, white at bottom
    {
        cout << endl<< y + 1;
        for (int x = 0; x < _DIMENSION; x++)
        {


            cout << "   #   ";


            if(_squares[x][y]->occupied()){

                _squares[x][y]->occupiedBy()->display();
            }else{
                cout << "  ";
            }

            if(x==_DIMENSION-1){
                cout << "   #   ";
            }

            if(x==_DIMENSION-1 && y!=0){
            cout << endl <<"    #        #        #        #        #        #        #        #        #";
            cout << endl <<"    #########################################################################";
            cout << endl <<"    #        #        #        #        #        #        #        #        #";
            }else if(x==_DIMENSION-1 && y==0){

                cout << endl <<"    #        #        #        #        #        #        #        #        #";
                cout << endl <<"    #########################################################################";

            }



        }

    }

    cout << endl <<"        A        B        C        D        E        F        G        H    "<<endl ;

}

Board* Board::_theBoard = NULL;
