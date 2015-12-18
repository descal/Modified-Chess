#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "piece.h"
#include "king.h"
#include<vector>

using namespace std;

class Player
{
public:

    /**
     * Creates a Player
     *
     * @params x, y the location of the square on the board
     */
    Player(string name, bool isWhite, King& myKing, vector<Piece*>& myPieces, bool humanity);

    /**
     * Default destructor
     */
    ~Player();

    /**
     * Make a move
     *
     * @return successful move made
     */
    bool makeMove();

    /**
     * checks if this player is in check
     *
     * @return if in check
     */
    bool inCheck();

    /**
     * Capture another piece
     *
     * @param aPiece the piece to be captured
     */
    void capture(Piece* aPiece);

    /**
     * Get the player's name
     *
     * @return the name
     */
    string getName() const;

    /**
     * Determines if this is the white player
     *
     * @return if is white
     */
    bool isWhite() const;

    /**
     * Get the total score for captured pieces
     *
     * @return score
     */
    int score() const;

     void guardar();

    /**
     * Get the set of this player's pieces
     *
     * @return the set of pieces
     */
    vector<Piece*>* myPieces() const;

    /**
     * Get this player's king
     *
     * @return the king
     */
    King* myKing() const;


private:

    // Private attributes
    bool _human;
    string _name;
    bool _isWhite;
    vector<Piece*>& _myPieces;
    set<Piece*> _capturedPieces;
    King& _myKing;

}; // Player

#endif
