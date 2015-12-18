#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "board.h"
using namespace std;

int main ()
{
    srand(time(NULL));

    Player* currentPlayer = NULL;

    // initialize a chess game and display the initial state
    Game::initialize();
    Board::getBoard()->displayBoard();

    // game loop in which players alternate making moves
    while(true)
    {
        currentPlayer = Game::getNextPlayer();
        while(!currentPlayer->makeMove())
        {
           // cout << "Invalid move... Try again." << endl;
        }
        Board::getBoard()->displayBoard();
    }

    return 0;
}
