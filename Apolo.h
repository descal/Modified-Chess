#ifndef APOLO_H
#define APOLO_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class Apolo : public Piece
{
 public:

    /**
    * Creates an Apolo
    *
    * @param color the color of the piece
    */
    Apolo(bool isWhite);

    /**
     * Default destructor
     */
    ~Apolo();

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



    void display() const;

    string displayName()const;

}; // Apolo

#endif
