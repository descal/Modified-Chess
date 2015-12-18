#ifndef GAME_H
#define GAME_H

#include <set>
#include <iostream>
#include "board.h"
#include "piece.h"
#include "player.h"
#include <vector>

using namespace std;

class Game
{
 public:

    /**
     * Destructor
     */
    ~Game();

    /**
     * Set up a new game of chess
     *
     */
    static void initialize();


    static void saveGame();
    /**
     * Choose random pieces
     *
     */
    static void selectRandomPieces(int randomnumber, bool PLAYER);

    /**
    * Get the player whose turn is next
    *
    * @return the player
    */
    static Player* getNextPlayer();

    /**
    * Get the player who is the opponent of the given player
    *
    * @param player the player
    * @return the opponent
    */
    static Player* opponentOf(Player& player);

 private:

    /**
     * Create a Game
     */
    Game();

    // Private attributes
    static Player* player1;
    static Player* player2;
    static Player* nextPlayer;
    static vector<Piece*> whitePieces;
    static vector<Piece*> blackPieces;

}; // Game

#endif
