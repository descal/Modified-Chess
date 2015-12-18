#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "restrictedpiece.h"
#include "square.h"

using namespace std;

class Rook : public Piece
{
 public:

    /**
    * Creates a Rook
    *
    * @param color the color of the piece
    */
    Rook(bool isWhite);

    /**
     * Default destructor
     */
    ~Rook();

    /**
    * Get the point value of the piece
    *
    * @return the value
    */
    int value() const;

    /**
    * Determines if the piece can legally move to a given square
    *
    * @param square the square to move to
    * @return if move is legal
    */
    bool checkMove(Square& location) const;

    /**
     * Display the piece
     * @param outStream the output stream
     */
    //    string toSave();

    void display() const;

    string displayName()const;

}; // Rook

#endif
